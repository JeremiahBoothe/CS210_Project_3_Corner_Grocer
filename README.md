# CS210_Project_3_Corner_Grocer

[Project Reflection](#Project-Reflection)
- [Summary](#Summary)
- [Achievements](#Achievements)
- [Enhancements](#Enhancement)
- [Challenges](#Challenges)
- [Support](#Support)
- [Transferable Skills](#Transferable-Skills)
- [Extensibility](#Extensibility)

[Project Documentation](#Project-Documentation)
- [Introduction](#Introduction)
- [Features and Functionality](#Features-and-Functionality)
	- [Automatic Conversion](#Automatic-Conversion)
	- [Error Handling](#Built-in-error-handling-of-ReadWrite--InputOutput)
	- [Timestamped Output Files](#Timestamped-Output-Files)

- [Menu Options](#Menu-Options-There-are-Four-Menu-Options-Available)
- [Troubleshooting Error Messages:](#Troubleshooting-Error-Messages)
	- [Could not open file CS210_Project_Three_Input_File.txt](#could-not-open-file-cs210_project_three_input_filetxt)
	- [Invalid Choice. Please try again.](#Invalid-Choice-Please-try-again)
	- [Item does not exist, please try again.](#Item-does-not-exist-please-try-again)

# **Project Reflection**

## Summary

*Summarize the project and what problem it was solving.*

Project three involved developing software for a grocery store named Corner Grocer. Their need was an easy way to identify how often each item in their produce section is being purchased. The problem was the current purchase system logged each item as a single entry. This could potentially cause hours of extra work as they hand-tally a long list of duplicates into a much shorter list with quantities, every single day.

My software addresses the issue by tallying each item, eliminating duplicates, and generating a unique list with individual entries and purchase frequencies. This list is exported with a timestamp to prevent accidental overwrites, providing a historical reference. Corner Grocer can easily view the list with numerical and histogram values, and search the list for individual items.

## Achievements
*What did you do particularly well?*

I approached the project with the end user in mind and had some creative ideas of what the implementation would require. Setting out not knowing if I'd succeed with my ideas or have to go in a different direction. I put in a lot of time and effort to test the boundaries of my idea. 

I utilized the C++ map to create unique keys based on item name, and assigned pointers to class objects as the value. There were many failed and partial successes along the way and even now the concepts I learned throughout the process have inspired more efficient approaches. The best thing I did was not give up, lost a bit of sleep unfortunately, but sometimes it's best to just let inspiration lead the way.

## Enhancement

*Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?*

My code is overall clean and well organized but as the functionality of the program grew, there were areas that ended up more coupled than I would have liked.

### Separation of Concerns

One example is the *map* and *menu* functions are grouped together. There were efforts toward separating them but some minor code issues resulting from gaps in understanding led to the current iteration. This is a process I have already made attempts at ultimately abandoning them for the assignment deadline. I will talk about that below in both *Security* and *Refactoring*.

### Security

While I do have a relatively decent understanding of scoping on a superficial level, at times I felt my application was subpar, and resulted in tossing functions into std for the sake of it rather than the need for it. I minimized that as much as I could get away with and still have the code function properly.

### Refactoring

The task of refactoring is not a big one for this program, there are a handful of operations done within a function, that could be moved into their own functions and achieve the *single responsibility principle*. The main reason for refactoring would be to achieve the separation of concerns.

## Challenges

*Which pieces of the code did you find most challenging to write, and how did you overcome this?* 

The first big challenge was dynamically creating objects. I'm familiar with manually instantiating a class and assigning it a name to create unique objects of the same type, but doing so dynamically was an entirely different set of challenges. The week prior my curiosity led me to experimenting with dynamically creating variable names with little success, although I could likely achieve it now that this project is finished. The solution is somewhat unique to the map, because I needed a place to store these dynamic creations to keep them alive through scope changes.  

Considering the requirements of the program, with the need to take an input that contains duplicates and return an output that is free of duplicates, a map seemed like a logical means to accomplish more with less, and paired nicely with dynamically creating unique class instantiations. So by this point I had the idea of creating the object, assigning the objects name to the key and the *unique_ptr* representation of the object to the value. This allowed me to remove redundancy right away, and my dynamic creations could survive in the map which could be passed around and worked with as needed. Figuring out how to pass around the map to other functions and apply pointers within the map to the correct object and even further at the quantity held in the object was the next big challenge.  It just took a bit of time and a lot of attempts but it worked out in the end.

Over the last week I struggled with a few issues regarding things not being in scope, I solved those issues through *#include,* and while I minimized that usage, I feel it wasn't ideal. I was also making attempts at using nested namespaces and anonymous namespaces to more thoughtfully control the access classes and functions didn't rely on *#include* and *using namespace std*; as a crutch.

## Support
*What tools or resources are you adding to your support network?*

Gaining(more->experience("C++")); helped me understand what's going on under the hood of higher level programming languages such as Kotlin, Java, Python.

There were some great reference links provided throughout the course as well that I've added to my personal notes in obsidian.

## Transferable Skills
*What skills from this project will be particularly transferable to other projects or course work?*

This is the first programming class where I was held to a professional standard, and that itself was extremely valuable. I had so many code smells that no matter how well my code might have worked for the task, it stunk. Now I have a clearer picture on what my future career (hopefully sooner than later) will look like. I would go as far as saying that how this class was presented completely changed every aspect of how I view and approach programming.

The linked list lab gave me some new insights into working with pointers that would could have worked as well. It also gave me some conceptual ideas of combining a map and a linked list.  With the map as somewhat of a hydra, with many heads of different object types, and each object type pointing to another object of the same type, so for example. GroceryItems is the map, there are produce, fruit, canned goods, etc... as unique categories within the map, and each category within the map branches out into a linked list of each object that falls under that category.

## Extensibility
*How did you make this program maintainable, readable, and adaptable?*

I did my best to name things appropriately, and focus on code aesthetic with consistent formatting. 

The use of an alias for the map helped simplify the arguments of functions so they were less cluttered looking which took a bit of load off my mind reading the full map definition every time. 
I adhered to SOLID principles when I could do so without breaking the code and avoided hard coded values. With just a few alterations some of the embedded variable values could be made accessible. 

Further, I have some ideas for creating an external config file that could be scanned in before readthe list to a map. The config file would contain the values to customize the name, location and extension of the input file, as well as the values for characters in case the '*' and '$' characters weren't desireable.

# **Project Documentation**
**Corner Grocer: Daily Purchase Software**

Jeremiah A. Boothe  
Department of Technology, Southern New Hampshire University

CS-210-J7357: Programming Languages

Professor Matthew Parker  
October 15, 2023

## **Introduction:**

Corner Grocer daily tally, the latest and greatest software from Chada Tech (since the interest rate calculator) provides a user-friendly way to combine single purchase items by name and quantity.  No more tallying long lists of duplicate words by hand, simply add your daily log of items to the directory with GroceryItem.exe, run the program, and spend more time with friends and family relaxing by the pool.

## **Features and Functionality:**

###	**Automatic Conversion:**

Converts daily purchase log automatically without the need for user input. Simply place the daily log file into the directory alongside GroceryItem.exe and run the program. The output file will automatically be generated containing each item and the quantity purchased.

### **Built in error handling of Read/Write & Input/Output:**

1. If a file is missing or cannot be opened an error will be displayed with the name of the file in question.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/14a6e6c8-9d1b-4e49-ae96-13de88ccb0ee)


2. Handles incorrect inputs at all levels and provides a new prompt to try again.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/429c4b11-e551-4d13-b73a-aa2877faad2c)

3. Upon execution a read/write message is displayed, for smaller files this may go unnoticed, and the menu will disappear immediately. 

4. When the menu options are displayed, everything worked correctly.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/604c81f1-8ef9-40ac-ab8f-62344d9bf9f2)

5. Search for item by name or display the full list in either integer representations or histogram representations of quantity.

6. Handles case when dealing with searches.  (ie. Yams, yAms, YaMs, etc.. are all perfectly valid entries.)

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/e05cfab7-7947-4a1f-a384-d9e1116e510b)

7. For larger files, with more time for the read/write process to occur, the read/write output messages will be visible. This is normal for very significantly large files. The program will continue to the menu when it has finished processing.

8. If an error message appears on screen at any point, see Troubleshooting.

### **Timestamped Output Files:**
- Each output file is generated with a unique name, using an international date and military time format: d:m:y:h:m:s.(ie., frequency_d_m_y_h_m_s.dat).

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/8f75ebd4-bc98-40cd-8520-4da53c9e1c93)

## **Menu Options: There are Four Menu Options Available:**
*Note: Press the corresponding number key followed by enter(return) to access each option.*

1. Menu option 1 allows you to search for specific grocery items by name. The item will be displayed with the daily total.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/00899ebe-cac7-4145-9970-155a0aa19fde)

2. Menu option 2 allows you to display all items purchased for the day with the quantity of purchase represented as an integer value.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/e75a946c-b82d-4ae9-9e72-074c9e35a7f0)

3. Menu option 3 allows you to display all items purchased for the day with the quantity of purchases in histogram form represented by the ‘$’ character. Say ka-ching when you see those dollar signs.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/e81299a5-2bb0-46cd-9276-ed2323d61907)

4. Menu option 4 exits the program.

![image](https://github.com/JeremiahBoothe/CS210_Project_3_Corner_Grocer/assets/78677784/ce44045c-0da6-4687-8afc-3de8c5875031)

## **Troubleshooting Error Messages:**

### **Could not open file CS210_Project_Three_Input_File.txt.**
- Ensure input file is correctly named **_CS210_Project_Three_Input_File.txt_**
- Ensure input file is in the directory with GroceryItem.exe

### **Invalid Choice. Please try again.**
- Make sure a single number value between one and four is being input.

### Item does not exist, please try again.
- Check spelling for any typos. When unsure if item exists, run option 2 or 3 and check the list.

