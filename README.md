# BetaBiz

A shop keeper's tools for all shop activities

![Flow](/resources/img/flow.png)
Step-by-step guide on how to start the project:

1. **Set Up Your Development Environment**: Make sure you have Python installed on your machine. If you don't, you can download it from the official Python website. You'll also need an Integrated Development Environment (IDE) or a text editor. PyCharm and Visual Studio Code are good options.

2. **Install Necessary Libraries**: You'll need several Python libraries for this project. You can install them using pip, which is a package manager for Python. Open your terminal or command prompt and type the following commands:

   - For SQLite: `pip install pysqlite3`
   - For PyQt (for GUI): `pip install PyQt5`
   - For schedule (for reminders): `pip install schedule`

3. **Design Your Database**: Before you start coding, it's a good idea to design your database. Decide what tables you'll need and what columns each table will have. Draw a diagram if it helps. Make sure each table has a primary key, and think about what relationships you'll need between tables.

4. **Create Your Database**: Now you can start coding. Write a Python script that connects to an SQLite database and creates the tables you've designed. You can use the `sqlite3` library for this. Make sure to test your script and check that it's creating the database correctly.

5. **Create Your GUI**: Next, start working on your graphical user interface (GUI). You can use the PyQt library for this. Start by creating the main window of your application, then add forms where you can enter new items, purchases, miscellaneous expenses, cash amounts, and credits. Also add tables or lists where you can view this data.

6. **Implement Database Operations**: Once your GUI is set up, you can start implementing the database operations. Write functions that can add new records to your tables, update existing records, and delete records. Also write functions that can retrieve records from the database and display them in your GUI.

7. **Implement Calculations**: Write functions that can calculate the total purchase amount per day, the total miscellaneous amount per day, the total cash on hand, and the total amount of credit. Also write a function that can calculate your sales based on this data.

8. **Implement Reminders**: Write a function that can check the `Credits` table for any credits that are more than three days old. You can use the `schedule` library to run this function at a specific time each day.

9. **Test Your Application**: As you're developing your application, make sure to test it regularly. Check that it's adding, updating, and deleting records correctly, and that it's calculating totals correctly. You can write test cases and use a testing framework like pytest to automate your tests.

10. **Iterate and Improve**: Once you have a basic version of your application working, you can start adding more features, such as the ability to generate reports, back up your database, or secure your data.
