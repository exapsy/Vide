#include "serialdatamanager.hpp"

SerialDataManager::SerialDataManager(QObject *parent, QWidget *widget)
    : QObject( parent ), widget( widget )
{
    serialRecorder = new SerialPortRecorder( parent, widget );
    // Debugging reasons
    connect(serialRecorder, SIGNAL( bytearrayReloaded( ) ),
            this, SLOT(readBytes( ) ) );

    connect(serialRecorder, SIGNAL(bytearrayReloaded()),
            this, SLOT( setData( ) ) );
}



void SerialDataManager::getUnfinishedValue( )
{
    // If last byte is not CR or NL
    while ( !(data.endsWith( '\n' ) ) && !(data.endsWith( '\r' ) ) && data.size( ) > 0 ) {
        carry.insert( 0,  data.right(1) );
        data.remove( data.size() - 1, 1 );
    }

    qDebug() << "Carry Kept : " << carry << endl;
}

void SerialDataManager::readBytes()
{
    qDebug() << getIntData( ) << endl;
}

// Pure Variables in Serial without Titles
QVector<QVector<int> > SerialDataManager::getIntData( const QByteArray &data )
{
    QVector<QVector<int> > integerGroups;
    // Anything that isn't digit or space, is taken away
    QRegExp escapeChars( "([^\\d\\s]{1,})" );
    QStringList dataToString = QString( data ).split( escapeChars,
                                                      QString::SkipEmptyParts );

    QRegExp splitGroupRegx ( "(\\s)" );
    for ( const auto group: dataToString ) {
        QStringList groupSplitted = group.split( splitGroupRegx,
                                                 QString::SkipEmptyParts );
        QVector<int> groupSplittedInt;
        for ( const QString member: groupSplitted ) {
            groupSplittedInt.append( member.toInt() );
        }
        integerGroups.append( groupSplittedInt );
    }

    return integerGroups;
}

QVector<QVector<int> > SerialDataManager::getIntData( )
{
    return getIntData( this->data );
}

QVector<QVector<double> > SerialDataManager::getDoubleData( const QByteArray &data )
{
    QVector<QVector<double> > doubleGroups;
    // Anything that isn't digit or comma or space, is taken away
    QRegExp escapeChars( "([^\\d\\s\\.]{1,})" );
    QStringList dataToString = QString( data ).split( escapeChars,
                                                      QString::SkipEmptyParts );

    QRegExp splitGroupRegx ( "(\\s)" );
    for ( const auto group: dataToString ) {
        QStringList groupSplitted = group.split( splitGroupRegx,
                                                 QString::SkipEmptyParts );
        QVector<double> groupSplittedDouble;
        for ( const auto member: groupSplitted ) {
            groupSplittedDouble.append( member.toDouble() );
        }
        doubleGroups.append( groupSplittedDouble );
    }

    return doubleGroups;
}

QVector<QVector<double> > SerialDataManager::getDoubleData( )
{
    return getDoubleData( this->data );
}

QVector<QVector<QString> > SerialDataManager::getStringData( const QByteArray &data )
{
    QVector<QVector<QString> > stringGroups;
    // Anything that isn't letter, digit or space, is taken away
    QRegExp escapeChars( "([\\000\\xFA-\\xFB\\uFFFF\\cI\\r\\0\\n])" );
    QStringList dataToString = QString( data ).split( escapeChars,
                                                      QString::SkipEmptyParts );

    QRegExp splitGroupRegx ( "(\\s)" );
    for ( const auto group: dataToString ) {
        QStringList groupSplitted = group.split( splitGroupRegx,
                                                 QString::SkipEmptyParts );
        stringGroups.append( groupSplitted.toVector( ) );
    }

    return stringGroups;
}

QVector<QVector<QString> > SerialDataManager::getStringData( )
{
    return getStringData( this->data );
}


// Get mapped data
QMap<QString, double> SerialDataManager::getMappedDoubles( const QByteArray &data )
{
    QMap<QString, double> mappedDoubles;
    QVector<QVector<QString>> stringData = getStringData ( data );

    for ( QVector<QString> group : stringData ) {
        for ( int i = 0; i < group.size(); i+=2 ) {
            mappedDoubles[group[i]] = group[i+1].toDouble();
        }
    }

    return mappedDoubles;
}

QMap<QString, double> SerialDataManager::getMappedDoubles( )
{
    return getMappedDoubles( this->data );
}

QMap<QString, int> SerialDataManager::getMappedIntegers( const QByteArray &data )
{
    Q_UNUSED( data );
    return QMap<QString, int>();
}

QMap<QString, int> SerialDataManager::getMappedIntegers( )
{
    return getMappedIntegers( this->data );
}


QByteArray SerialDataManager::getData( ) const
{
    return data;
}

void SerialDataManager::setData( )
{
    data.clear( );
    if ( carry.capacity( ) > 0 ) {
        data.insert( 0, carry );
        carry.clear( );
    }

    data.append( serialRecorder->getLastBytearray() );
    getUnfinishedValue( );
    emit dataChanged( );
}
