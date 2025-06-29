# CS-300-DSA-Analysis-and-Design
# CS-300: Data Structures and Algorithms Portfolio Submission

##  Project One: Data Structure Analysis
In Project One, I analyzed the runtime and memory usage of different data structures for storing course information. I evaluated vectors, maps, and linked lists based on their efficiency for tasks such as searching, inserting, and sorting course data. My analysis led me to choose a `map` for its fast key-based access and ease of sorting keys alphanumerically.

## Project Two: Advising Assistance Program
In Project Two, I built a command-line C++ application that helps academic advisors retrieve course information, including prerequisites, and display all courses in sorted order. The program reads from a CSV file and stores course objects using a `map` data structure.



## Reflection

### What was the problem you were solving?
The main challenge was to design and implement a system that could efficiently load, store, sort, and retrieve course information to assist academic advisors. The application had to handle course relationships through prerequisites and provide accurate, structured output.

### How did you approach the problem?
I focused on selecting the right data structure that balanced performance and simplicity. I chose a `map` because it allows quick lookups by course number and automatically sorts by keys, which simplified the task of printing an ordered course list. I structured the code with helper functions for trimming strings, converting input to uppercase, and parsing CSV data.

### How did you overcome roadblocks?
I encountered file-reading issues and course lookup mismatches, especially with case sensitivity and trimming whitespace. I overcame these by implementing utility functions like `trim()` and `toUpper()` to clean and standardize input. I also carefully validated user input and added error handling to guide the user.

### How has this project expanded your approach to designing software?
This project emphasized the importance of planning and structuring code before jumping into implementation. By separating logic into distinct functions and using clear data structures, I saw how design decisions directly impact program clarity and maintainability.

### How has this project evolved your coding practices?
I now place more importance on:
- Writing readable, modular code
- Including inline comments
- Using meaningful variable names
- Designing programs that are easy to test and expand
This project also reminded me to always validate input and consider edge cases.





