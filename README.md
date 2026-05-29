📒 Address Book Application
A console-based Address Book application written in C that allows users to manage their contacts through a simple menu-driven interface. Contacts are saved to a CSV file and automatically loaded on startup.

📋 Features

Create Contact — Add a new contact with name, phone number, and email
Search Contact — Find contacts by name, phone number, or email
Edit Contact — Update an existing contact's details
Delete Contact — Remove a contact from the address book
List All Contacts — Display all saved contacts
Save & Exit — Persist contacts to a file and exit the application


🛠️ Project Structure
address-book/
├── main.c          # Entry point; menu loop and user interaction
├── contact.c       # Core logic: create, search, edit, delete, list, validation
├── contact.h       # AddressBook and Contact struct definitions; function declarations
├── file.c          # File I/O: save and load contacts from contact.csv
├── file.h          # File function declarations
└── contact.csv     # Auto-generated data file (created on first save)

✅ Input Validation
The application enforces the following rules before saving a contact:
FieldRulesNameLetters only, minimum 3 characters, no special characters or digitsPhoneExactly 10 digits, must start with 6–9, no duplicates allowedEmailLowercase only, single @ and ., must end with .com, no duplicates allowed
Each field allows up to 3 attempts before the operation is cancelled.

🚀 Getting Started
Prerequisites

GCC compiler (or any C compiler)
Linux / macOS / Windows with MinGW

Compilation
bashgcc main.c contact.c file.c -o addressbook
Run
bash./addressbook

💾 Data Persistence
Contacts are saved to contact.csv in the current directory when the user selects Save and Exit. The file is automatically loaded on the next run, so your data is never lost between sessions.

📌 Usage Example
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit
Enter your choice: 1

Enter your name: Vamsi D
Enter your number: 9876543210
Enter your email id: vamsi@example.com

👤 Author
Vamsi D
