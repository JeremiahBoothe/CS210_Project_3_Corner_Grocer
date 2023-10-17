# CS210_Project_3_Corner_Grocer



[Project Documentation](#Project-Documentation)
- [Introduction](#Introduction)
- [Features and Functionality](#Features-and-Functionality)
	- [Automatic Conversion](#Automatic-Conversion)
	- [Error Handling](#Built-in-error-handling-of-Read/Write-&-Input/Output)
	- [Timestamped Output Files](#Timestamped-Output-Files)

$${\color{red}
- [Menu Options](#Menu-Options)
- [Troubleshooting Error Messages:](#Troubleshooting-Error-Messages)
	- [Could not open file CS210_Project_Three_Input_File.txt](#Could-not-open-file-CS210_Project_Three_Input_File.txt.)
	- [Invalid Choice. Please try again.](#Invalid-Choice.-Please-try-again.)
	- [Item does not exist, please try again.](#-Item-does-not-exist,-please-try-again)

	}$$

[Project Reflection](#Project-Reflection)
- [Summary](#Introduction)
- [Acheivements](#Achievements)
- [Enhancements](#Enhancement)
- [Challenges](#Introduction)
- [Support](#Support)
- [Transferrable Skills](#Transferrable-Skills)
- [Extensibility](#Extensibility)

# **Project Reflection**
## Summary
*Summarize the project and what problem it was solving.*

## Achievements
*What did you do particularly well?*

## Enhancement
*Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?*

## Challenges
*Which pieces of the code did you find most challenging to write, and how did you overcome this?* 

## Support
*What tools or resources are you adding to your support network?*

## Transferable Skills
*What skills from this project will be particularly transferable to other projects or course work?*

## Extensibility
*How did you make this program maintainable, readable, and adaptable?*

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

