# CS210_Project_3_Corner_Grocer

**Corner Grocer: Daily Purchase Software**

Jeremiah A. Boothe  
Department of Technology, Southern New Hampshire University

CS-210-J7357: Programming Languages

Professor Matthew Parker  
October 15, 2023

# **Introduction:**

Corner Grocer daily tally, the latest and greatest software from Chada Tech (since the interest rate calculator) provides a user-friendly way to combine single purchase items by name and quantity.  No more tallying long lists of duplicate words by hand, simply add your daily log of items to the directory with GroceryItem.exe, run the program, and spend more time with friends and family relaxing by the pool.

# **Features and Functionality:**

## **Automatic Conversion:**

Converts daily purchase log automatically without the need for user input. Simply place the daily log file into the directory alongside GroceryItem.exe and run the program. The output file will automatically be generated containing each item and the quantity purchased.

## **Built in error handling of Read/Write & Input/Output:**

1.     If a file is missing or cannot be opened an error will be displayed with the name of the file in question.  
![[Pasted image 20231016020451.png]]

2.     Handles incorrect inputs at all levels and provides a new prompt to try again.
![[Pasted image 20231016020510.png]]

3.     Upon execution a read/write message is displayed, for smaller files this may go unnoticed, and the menu will disappear immediately. 

4.     When the menu options are displayed, everything worked correctly.  
![[Pasted image 20231016020534.png]]

5.     Search for item by name or display the full list in either integer representations or histogram representations of quantity.

6.     Handles case when dealing with searches.  (ie. Yams, yAms, YaMs, etc.. are all perfectly valid entries.)  ![[Pasted image 20231016020601.png]]

7.     For larger files, with more time for the read/write process to occur, the read/write output messages will be visible. This is normal for very significantly large files. The program will continue to the menu when it has finished processing.

8.     If an error message appears on screen at any point, see Troubleshooting.

# **Timestamped output files:**

·       Each output file is generated with a unique name, using an international date and military time format: d:m:y:h:m:s.(ie., frequency_d_m_y_h_m_s.dat). ![[Pasted image 20231016020627.png]]

# **Menu Options:**

## **There are 4 menu options available:**

**Note: Press the corresponding number key followed by enter(return) to access each option.**

1.     Menu option 1 allows you to search for specific grocery items by name. The item will be displayed with the daily total.

![[Pasted image 20231016020647.png]]

2.     Menu option 2 allows you to display all items purchased for the day with the quantity of purchase represented as an integer value.

![[Pasted image 20231016020707.png]]

3.     Menu option 3 allows you to display all items purchased for the day with the quantity of purchases in histogram form represented by the ‘$’ character. Say ka-ching when you see those dollar signs. 

![[Pasted image 20231016020723.png]]

4.     Menu option 4 exits the program.

![[Pasted image 20231016020741.png]]

# **Troubleshooting:**

## **Error Message:** **Could not open file** **CS210_Project_Three_Input_File.txt**

·       Ensure input file is correctly named **_CS210_Project_Three_Input_File.txt_**

·       Ensure input file is in the directory with GroceryItem.exe

## Error Message: Invalid Choice. Please try again.

·       Make sure a single number value between one and four is being input.

## Error Message: Item does not exist, please try again.

·       Check spelling for any typos. When unsure if item exists, run option 2 or 3 and check the list.
 
