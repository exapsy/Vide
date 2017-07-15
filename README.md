# Vide
-----

<p align="center">
    <a href="https://github.com/general656/Vide/blob/master/README.md#what-is-it-"><b>What is it?</b></a> | 
    <a href="https://github.com/general656/Vide/blob/master/README.md#all-started-when-i-couldnt-find-a-software-that-fits-my-needs"><b>How did all start?</b></a> |
    <a href="https://github.com/general656/Vide/blob/master/README.md#abilities"><b>Abilities</b></a> |
    <a href="https://github.com/general656/Vide/blob/master/README.md#how-to-use"><b>How to use</b></a>
</p>

----
## <h1 align="center">What is it ?</h1>
**Vide** is a **free** and **open-source** tool for **Serial Communication Reading** and **Data Visualization**. 

Its purpose is to get _Input_ from a **Serial device** and generate an output for the **Plot Graphs** of the Application.

For example:
### Input
> varName1 552.23 varName2 23.202\r
### Output
**Vide** will grab each variable's name and value and create a **Variable object**. This **Variable object** can be displayed on a **Plot Graph** of the corresponding **Serial Port**.

---------------

## <h1 align="center">All started when I couldn't find a software that fits my needs.</h1>
* The first one had to be bought after the trial and it didn't really worth it. It had a really big delay when it was reading live values, around 1 minute(!) and it needed an **external Arduino Library** to read the values. I wanted something simple, without the need of unnecessary external libraries, just a **quick serial output**.
* The other one was just poor quality, unusable and much more complex. Why all these programs were so complex? All I wanted was to visualize some values that we got from the Serial Input!
* Most of them couldn't support **Database Communication** and I'm about to make it possible via UDP **Two-Way Binding Connection** 

And they all were either pretty **complicated** and with **problems/bugs**. I wanted to make something simple that everyone could use and it would be great for a **High End** *AND* a **Low End** user. 

Something that could read many **Live Serial Data** and **Saved Data** simultaneously and visualize them in the way you like.

---------
## <h1 align="center">Abilities</h1>

* - [x] Can read Live Data
* - [ ] Can read Saved **.csv** Data.
* - [ ] **Vide** is intended to be **Multi-Threaded** to provide a much **faster** and **cleaner** use to the **Final User**. 
* - [ ] It provides the ability to visualize each Variable in the plot of your preference. You can either visualize all the variables in one and only plot **OR** all the variables in their own plot.
* - [ ] Can read many **Serial Ports** together
* - [ ] Supports online/offline **Database Communication**

---------
## <h1 align="center">How to use:</h1>

### Settings:
1. Choose the **total number** of **variables** you want to read
1. Select the **Serial Port** you want to read if you want **Live Input**. (Not Available) Otherwise, select the **.csv File** you want to read.
    * **Serial Output** has to be in the following format `{Variable Name1}: {Double Value1} {Variable Name2}: {Double Value2} ... {CR/NL or Both}`. (read **_Writing Serial Output_**).
    * **.csv** File has to be in the following format `Milliseconds;Name;Value;`
1. (**optional** - Not Available) If you're reading through a database then connect to the database and select the table you want to read.
1. (**optional** - Not Available) If you're writing to a database then connect to the database and select the table you want to write to.

### Writing Serial Output ? Simple AF:

First you have to select the total number of variables there is on each {**CR\NL or both**}.

**Serial Output** has to be in the following **format**:
> {Variable Name}: {Double/Float Value} {Variable Name2:}: {Double/Float Value2} ....{CR/NL or both}

### Example:
> **Variables:** [ **2** ]
> Microphone Input: 525.00 db: 20.00\n\rMicrophone Input: 763.00 db: 50.00\n\r

### Vide's Intepretation:
##### 1:
Variable Name | Variable Value |
--------------|----------------|
Microphone Input | 525.00
db | 20.00

##### 2:
Variable Name | Variable Value |
--------------|----------------|
Microphone Input | 763.00
db | 50.00

### The rule here is:
* You can insert as many variables you want ( unless they're too many )
* Each **Variable** has a **name** and a **value**
  * **Name**: 
    1. Can have spaces
    1. Ends with an **unspaced** *colon* `// Microphone Input : << Error: Colon has space before`
    1. Next to it is always the **value**
  * **Value**:
    1. Is always next to **name**
    1. Should be a **double** value
    1. Next to it is either another Variable with the same properties, or a {CR/NL or both}

#### `For the sake of simplicity:` The rules above must be used strictly. They were made to be simple and comfortable to the user. But don't try to misuse them because `Vide` won't be able to handle any other Input. 

---------
### I hope this product gets the love it needs.
