# Vide
**Vide** is a **free** and **open-source** tool for **Serial Communication Reading** and **Data Visualization**. 

Its purpose is to get _Input_ from a **Serial device** and generate an output for the **Plot Graphs** of the Application.

For example:
### Input
> varName1 552.23 varName2 23.202\r
### Output
**Vide** will grab each variable's name and value and create a **Variable object**. This **Variable object** can be displayed on a **Plot Graph** of the corresponding **Serial Port**.

---------------

## All started when I couldn't find a software that fits my needs. 
* The first one had to be bought after the trial and it didn't really worth it. It had a really big delay when it was reading live values, around 1 minute(!) and it needed an **external Arduino Library** to read the values. I wanted something simple, without the need of unnecessary external libraries, just a **quick serial output**.
* The other one was just poor quality, unusable and much more complex. Why all these programs were so complex? All I want is to visualize some values that we got from the Serial Input!
* Most of them couldn't support **Database Connections** and I'm about to make it possible via UDP One-Way connection

And they all were either pretty **complicated** and with **problems/bugs**. I wanted to make something simple that everyone could use and it would be great for a **High End** *AND* a **Low End** user. 

Something that could read many **Live Serial Data** and **Saved Data** simultaneously and visualize them in the way you like.
---------
## Abilities

* **Vide** is intended to be **Multi-Threaded** to provide a much **faster** and **cleaner** use to the **Final User**. 
* It provides the ability to visualize each Variable in the plot of your preference. You can either visualize all the variables in one and only plot **OR** all the variables in their own plot.
* Can read Live Data
* - [ ] Can read Saved **.csv** Data.
---------
### I hope this products gets the love it needs.
