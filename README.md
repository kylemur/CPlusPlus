# Overview

I have experience with C and C#, so I thought it would be helpful to also learn C++. 

This program manages inventory for products and saves the data (name, price, and quantity) to a text document. The user can display all inventory, search for products, add new products, and increase or decrease the quantity of existing products.

Many companies use C++ and/or C#, so I wanted to understand the similarities and differences of the languages. I learned that C++ can use -> (arrow character like in C) or . (dot character like in C# or Python) to access attributes and methods. C++ is different from other languages that I know because ituses >> and << characters for input and output.


[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

The first thing I did with this project was start learning the basics. I watched some YouTube tutorials and took notes of unique aspects of C++. I also used websites like geeksforgeeks.org to learn about the new and delete operators. Copilot was helpful to find syntax errors and explain the corrections. 

I included four libraries: iostream, vector, memory, fstream. The only namespace that I used was std. This was convenient because I only needed to put at the top of the file "using namespace std;" instead of std:: before methods like cout and cin.

# Useful Websites

- [C++ Tutorial - YouTube](https://www.youtube.com/watch?v=RSDzvlXmQi4)
- [GeeksforGeeks](https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/)

# Future Work

- Display similar product names and files if no exact match is found.
- Add a back feature that allows the user to go back a step if incorrect input was entered.
- Move some code from the main() function to the Product and Inventory classes to make it cleaner and easier to read.