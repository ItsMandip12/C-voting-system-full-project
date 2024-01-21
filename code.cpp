#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <chrono>
using namespace std;

class System {
private:
set<string> votedUsers;
public:
void displayWelcomeSlide() {
    char choice;

    do {
        system("cls");
        cout<< R"(__     __    _   _               ____            _                
\ \   / /__ | |_(_)_ __   __ _  / ___| _   _ ___| |_ ___ _ __ ___  
 \ \ / / _ \| __| | '_ \ / _` | \___ \| | | / __| __/ _ \ '_ ` _ \
  \ V / (_) | |_| | | | | (_| |  ___) | |_| \__ \ ||  __/ | | | | |
   \_/ \___/ \__|_|_| |_|\__, | |____/ \__, |___/\__\___|_| |_| |_|
                         |___/         |___/                       )";

       
        system("color 0A");
        // Menu options
        cout << "\n\n\n----------------------------------------\n";
        cout << " welcome...Please select an option:\n";
        cout << " 1. Enter voting System\n";
        cout << " 2. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Starting the system...\n";
                displayFirstPage();
                break;
            case '2':
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please choose again..\n";
                Sleep(2000);
                displayWelcomeSlide();
                break;
        }

        cout << "\nPress any key to continue...";
        getch();  // Wait for a key press
    } while (choice != '2');
}
void displayFirstPage() {
char choice;

do {
system("cls"); // Clear the console screen
system("color 01");
cout << "----------------------------------------\n";
cout << " Voting System Main Menu\n";
cout << "----------------------------------------\n";
cout << " Use as:\n";
cout << " 1. VOTER\n";
cout << " 2. ADMIN\n";
cout<<  " 3. Results\n";
cout << " 4. Back\n";
cout << "----------------------------------------\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case '1':
cout << "Redirecting to Voter interface...\n";
voter();
break;
case '2':
cout << "Redirecting to Admin...\n";
loginadmin();
break;
case '3':
  readVotingResults();
  break;
case '4':
cout << "Back\n";
displayWelcomeSlide();
break;
default:
cout << "Invalid option please choose again..\n";
Sleep(2000);
displayFirstPage();
break;
}

if (choice != '4') {
cout << "\nPress any key to continue...";
getch(); // Wait for a key press
}
} while (choice != '4');
}

void voter() {
system("cls");
system("color 03");
char choice;
cout << "Enter your choice: \n";
cout << "----------------------------------------\n";
cout << " 1. REGISTER\n";
cout << " 2. LOGIN\n";
cout << " 3. Back\n";
cout << "----------------------------------------\n";
cin >> choice;

switch (choice) {
case '1':
cout << "Redirecting to Registration interface...\n";
registerVoter();
break;
case '2':
cout << "Redirecting to Login...\n";
LoginVoter();
break;
case '3':
cout << "Back\n";
displayWelcomeSlide();
break;
default:
cout << "Invalid option please choose again..\n";
Sleep(2000);
displayFirstPage();
break;
}
}

struct Person {
string fullName;
string nationalId;
string dateOfBirth;
string gender;
string fathersName;
string mothersName;
string placeOfBirth;
string position;
string ac_qua;
string profession;
string agenda;
string social_work;
};
Person user;
string password;
bool voterLoggedIn = false;
bool votedMayor = false;
bool votedSubmayor = false;
bool votedSecretary = false;

void registerVoter() {
        system("cls");
        system("color 04");
        cout << "----------------------------------------\n";
        cout << " Registration Page as a voter\n";
        cout << "----------------------------------------\n";

        // Full Name input with validation
        do {
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "Full Name: ";
            getline(cin >> ws, user.fullName);
            count++;
        } while (!isValidName(user.fullName));
      system("cls");
        // Date of Birth input with validation
        do {
           
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "Date of Birth(yyyy/mm/dd): ";
            getline(cin >> ws, user.dateOfBirth);
            count++;
        } while (!isValidDateOfBirthFormat(user.dateOfBirth) || !isUserAbove18(user.dateOfBirth));

       system("cls");
        // Gender input with validation
        do {
       
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "Gender (Male/Female/Others): ";
            getline(cin >> ws, user.gender);
            count++;
        } while (!isValidGender(user.gender));
        system("cls");
        // Father's Name input with validation
        do {
             
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "Father's Name: ";
            getline(cin >> ws, user.fathersName);
            count++;
        } while (!isValidName(user.fathersName));
        system("cls");
        // Mother's Name input with validation
        do {
           
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "Mother's Name: ";
            getline(cin >> ws, user.mothersName);
            count++;
        } while (!isValidName(user.mothersName));
        system("cls");
        //placce of birth validation
        do{
             
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "Place of Birth(District): ";
            getline(cin >> ws, user.placeOfBirth);
            count++;
        } while (!isValidName(user.placeOfBirth));
        system("cls");
        //national card validation
        do{
           
            int count=0;
            if(count>0)
            {
                cout<<"Re-enter it in correct format";
            }
            cout << "National ID Card Number: ";
            getline(cin >> ws, user.nationalId);
            count++;
        } while(!isValidNationalId(user.nationalId));
     
        ofstream outFile("C:\\Users\\Mandeep\\Desktop\\VOTINGPROJECT\\database\\user_info\\user_info.txt", ios::app); // Open file in append mode

        if (outFile.is_open()) {
            outFile << "\n----------------------------------------\n";
            outFile << "Full Name: " << user.fullName << endl;
            outFile << "National ID Card Number: " << user.nationalId << endl;
            outFile << "Date of Birth(yyyy/mm/dd): " << user.dateOfBirth << endl;
            outFile << "Gender: " << user.gender << endl;
            outFile << "Father's Name: " << user.fathersName << endl;
            outFile << "Mother's Name: " << user.mothersName << endl;
            outFile << "Place of Birth(District): " << user.placeOfBirth << endl;
            outFile << "National ID Card Number: " << user.nationalId << endl;
            password = generateRandomPassword();
            outFile << "Generated password: " << password << endl;
            outFile << "\n----------------------------------------\n";
            cout << "Your password is : " << password << "\n";
            cout << "\n----------------------------------------\n";
            cout << "Please note it if you forget this password you won't be able to login\n";
            cout << "----------------------------------------\n";

            cout << "\nRegistration successful! Information saved\n";
        } else {
            cout << "Error opening file for writing.\n";
        }

        cout << "To Redirect to the main menu press any key...\n";
        getch();
        displayFirstPage();
    }

private:
    // Function to check if a National ID Card Number is valid
    bool isValidNationalId(const string& nationalId) {
        // Simple validation: Check if the length is reasonable
        return nationalId.length() >= 6 && nationalId.length() <= 20;
    }

    // Function to check if the gender is valid
    bool isValidGender(const string& gender) {
        // Allow "Male," "Female," or "Others" (case-insensitive)
        return gender == "Male" || gender == "Female" || gender == "Others" ||
               gender == "male" || gender == "female" || gender == "others";
    }

    // Function to check if the name consists only of characters
    bool isValidName(const string& name) {
        for (char ch : name) {
            if (!isalpha(ch) && ch != ' ') {
                cout << "Invalid characters in the name. Please enter a name consisting only of characters and spaces.\n";
                return false;
            }
        }
        return true;
    }


    // Function to check if the date of birth is in the format of yyyy/mm/dd
    bool isValidDateOfBirthFormat(const string& dateOfBirth) {
        // Validate format using a simple check
        return dateOfBirth.length() == 10 && dateOfBirth[4] == '/' && dateOfBirth[7] == '/' &&
               isdigit(dateOfBirth[0]) && isdigit(dateOfBirth[1]) && isdigit(dateOfBirth[2]) && isdigit(dateOfBirth[3]) &&
               isdigit(dateOfBirth[5]) && isdigit(dateOfBirth[6]) && isdigit(dateOfBirth[8]) && isdigit(dateOfBirth[9]);
    }
   bool isUserAbove18(const string& dateOfBirth) {
    // Validate date format
    if (dateOfBirth.length() != 10 || dateOfBirth[4] != '/' || dateOfBirth[7] != '/') {
        return false;
    }

    // Parse year, month, day
    int year, month, day;
    if (sscanf(dateOfBirth.c_str(), "%d/%d/%d", &year, &month, &day) != 3) {
        return false;
    }

    // Validate date components
    if (year < 1930 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Get current date
    time_t now = time(nullptr);
    tm* tm_now = localtime(&now);

    // Calculate age
    int age = tm_now->tm_year + 1900 - year;
    if (tm_now->tm_mon + 1 < month || (tm_now->tm_mon + 1 == month && tm_now->tm_mday < day)) {
        age--;
    }

    return age >= 18;
}
   
    // Function to generate a random password
    string generateRandomPassword() {
        const string alphanum = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

        srand(static_cast<unsigned int>(time(0))); // Seed using current time

        string password;
        for (int i = 0; i < 6; i++) {
            password += alphanum[rand() % alphanum.size()];
        }

        return password;
    }
void LoginVoter() {
votedMayor=false;
votedSecretary=false;
votedSubmayor=false;
string filename = "C:\\Users\\Mandeep\\Desktop\\VOTINGPROJECT\\database\\user_info\\user_info.txt";
string enteredID, enteredPassword;
system("cls");
system("color 05");
cout << "Enter your ID(ID is the National ID card number): ";
cin >> enteredID;

cout << "Enter your password: ";
enteredPassword = getHiddenInput();

if (checkCredentials(filename, enteredID, enteredPassword)) {
cout << "Login successful! Welcome, " << enteredID << "!" << endl;

startVoting(enteredID);
} else {
cout << "Login failed. Incorrect ID or password." << endl;
}
}

// to check id password
bool checkCredentials(const string &filename, const string &enteredID, const string &enteredPassword
) {

ifstream file("C:\\Users\\Mandeep\\Desktop\\VOTINGPROJECT\\database\\user_info\\user_info.txt", ios::in);
if (!file) {
cerr << "Error opening file: " << filename << endl;
return false;
}

string line;
bool foundID = false;
bool foundPassword = false;

while (getline(file, line)) {
// Find the line containing "National ID Card Number"
if (line.find("National ID Card Number: " + enteredID) != string::npos) {
foundID = true;
// Move to the next line (password line)
getline(file, line);
// Check if the line contains the correct password
if (line.find("Generated password: " + enteredPassword) != string::npos) {
foundPassword = true;
break; // Stop searching after finding both ID and password
}
}
}

file.close();

if (foundID && foundPassword) {
cout << "ID and password are correct" << endl;
return true;
}
else if (foundID) {
cout << "Invalid password" << endl;
}
else {
cout << "Invalid ID" << endl;
}

return false;
}
string getHiddenInput() {
        const char BACKSPACE = 8;
        const char ENTER = 13;

        string password;
        char ch;

        while ((ch = _getch()) != ENTER) {
            if (ch == BACKSPACE) {
                if (!password.empty()) {
                    cout << "\b \b"; // Move the cursor back and erase the character
                    password.pop_back();
                }
            } else {
                cout << '*';
                password += ch;
            }
        }

        cout << endl;
        return password;
    }
void startVoting(const string& voterID) {
    // Check if the voter has already voted
    if (votedUsers.find(voterID) != votedUsers.end()) {
        cout << "You have already voted. Cannot vote again." << endl;
        return;
    }

    // Load existing voted IDs from a file
    set<string> votedIDs;
    loadVotedIDsFromFile(votedIDs);

    // Check if the voter has voted before
    if (votedIDs.find(voterID) != votedIDs.end()) {
        cout << "You have already voted. Cannot vote again." << endl;
        return;
    }

    votedUsers.insert(voterID);
    votedIDs.insert(voterID);

    // Save the updated voted IDs to a file
    saveVotedIDsToFile(votedIDs);

    // Define positions and candidates
    vector<string> positions = {"Mayor", "Submayor", "Secretary"};
    vector<vector<string>> candidates = {{"Ram Paudel", "Sita Tiwari", "Manish Dhamala"},
                                        {"Nitya Bajgain", "Gita Kattel", "Paras Thapa"},
                                        {"Arjun Sherpa", "Dipesh Shah", "Ridam Gautam"}};

    // Initialize votes to 0 for each candidate
    vector<int> votes(positions.size() * candidates[0].size(), 0);

    // Load existing votes from a file (if available)
    loadVotesFromFile(votes);

    char choice;

    for (size_t positionIndex = 0; positionIndex < positions.size(); ++positionIndex) {
        system("cls");
        system("color 06");
        cout << "----------------------------------------\n";
        cout << " Voting Section\n";
        cout << "----------------------------------------\n";

        // Display available positions and candidates for the current position
        cout << "Choose the candidate for " << positions[positionIndex] << ":\n";
        for (size_t j = 0; j < candidates[positionIndex].size(); ++j) {
            cout << j + 1 << ". " << candidates[positionIndex][j] << endl;
        }

        // Voter casts a vote
        size_t candidateIndex;
        cout << "Enter the candidate index you want to vote for: ";
        cin >> candidateIndex;

        // Check if the entered candidate index is valid
        if (candidateIndex >= 1 && candidateIndex <= candidates[positionIndex].size()) {
            // Update the vote count without replacing the existing count
            votes[positionIndex * candidates[0].size() + candidateIndex - 1]++;
            markVoted(positionIndex);
            cout << "Vote cast successfully for " << positions[positionIndex] << "!" << endl;
        } else {
            cout << "Invalid candidate index. Vote not cast." << endl;
            --positionIndex;  // Decrement to vote for the same position again
        }

        // Ask if the voter wants to cast another vote
        cout << "Do you want to cast another vote? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;  // Exit the loop if the voter doesn't want to cast another vote
        }
    }
    cout << "----------------------------------------\n";
    cout << "Thank you for voting! The voting process has been completed." << endl;

    // Save the updated votes to a file
    saveVotesToFile(votes);
    saveresults(positions, candidates, votes);

   
}



private:
void loadVotesFromFile(vector<int>& votes) {
ifstream file("votes.txt", ios::in);
if (!file) {
cerr << "Error opening file for reading votes." << endl;
return;
}

for (int& vote : votes) {
file >> vote;
}

file.close();
}

void saveVotesToFile(const vector<int>& votes) {
ofstream file("votes.txt", ios::out);
if (!file) {
cerr << "Error opening file for writing votes." << endl;
return;
}

for (const int& vote : votes) {
file << vote << " ";
}

file.close();
}
void loadVotedIDsFromFile(set<string>& votedIDs) {
ifstream file("votedIDs.txt", ios::in);
if (!file) {
cerr << "Error opening file for reading voted IDs." << endl;
return;
}

string id;
while (file >> id) {
votedIDs.insert(id);
}

file.close();
}

void saveVotedIDsToFile(const set<string>& votedIDs) {
ofstream file("votedIDs.txt", ios::out);
if (!file) {
cerr << "Error opening file for writing voted IDs." << endl;
return;
}

for (const string& id : votedIDs) {
file << id << " ";
}

file.close();
}


private:
// Check if the voter has already voted for a specific position
bool hasVoted(size_t positionIndex) {
switch (positionIndex) {
case 0:
return votedMayor;
case 1:
return votedSubmayor;
case 2:
return votedSecretary;
default:
return false;
}
}

// Mark the voter as voted for a specific position
void markVoted(size_t positionIndex) {
switch (positionIndex) {
case 0:
votedMayor = true;
break;
case 1:
votedSubmayor = true;
break;
case 2:
votedSecretary = true;
break;
}

}
void loginadmin()
{
    system("cls");
    system("color 08");
string ID="889900",password="admin",ID1,password1;
cout<<"Enter ID: "<<endl;
cin>>ID1;
cout<<"Enter Password: "<<endl;
password1=getHiddenInput();
if(ID==ID1 && password==password1)
{
cout<<"Logged in"<<endl;
admin();
}
else{
cout<<"Wrong ID and password try again...!!"<<endl;
Sleep(2000);
displayFirstPage();
}

}
void admin() {
system("cls");
system("color 09");
ifstream inFile("C:\\Users\\Mandeep\\Desktop\\VOTINGPROJECT\\database\\user_info\\user_info.txt", ios::in);
if (!inFile) {
cerr << "Error opening file." << endl;
return;
}

cout << "----------------------------------------\n";
cout << " Admin: Options\n";
cout << "----------------------------------------\n";
cout << " 1. View All User Details\n";
cout << " 2. Check Voting Status for a User\n";
cout << " 3. Search user data by National ID\n";
cout << " 4. Public voting results\n";
cout << " 5. Back\n";
cout << "----------------------------------------\n";
cout << "Enter your choice: ";

char choice;
cin >> choice;

switch (choice) {
case '1':
viewAllUserDetails(inFile);
break;
case '2':
checkVotingStatus();
break;
case '3':
searchUserByNationalID(inFile);
break;
case '4':
public_result();
break;
case '5':
// Back to main menu
displayFirstPage();
break;
default:
cout << "Invalid option. Returning to main menu.\n";
displayFirstPage();
break;
}
}

void viewAllUserDetails(ifstream& inFile) {
    system("color 0A");
inFile.clear();
inFile.seekg(0, ios::beg); // Move file pointer to the beginning

string line;
while (getline(inFile, line)) {
// Exclude lines containing passwords
if (line.find("Generated password: ") == string::npos) {
cout << line << endl;
}
}

inFile.close();

cout << "\nPress any key to continue...";
getch(); // Wait for a key press
admin(); // Return to admin options
}

void checkVotingStatus() {
    system("color 0B");
cout << "Enter the National ID Card Number to check voting status: ";
string userID;
cin >> userID;

if (votedUsers.find(userID) != votedUsers.end()) {
cout << "Voter " << userID << " has voted.\n";
} else {
cout << "Voter " << userID << " has not voted.\n";
}

cout << "\nPress any key to continue...";
getch(); // Wait for a key press
admin(); // Return to admin options
}
void searchUserByNationalID(ifstream& inFile) {
    system("color 0C");
cout << "Enter the National ID Card Number to search for: ";
string searchID;
cin >> searchID;

bool found = false;
inFile.clear();
inFile.seekg(0, ios::beg); // Move file pointer to the beginning

string line;
while (getline(inFile, line)) {
size_t pos = line.find("National ID Card Number: " + searchID);
if (pos != string::npos) {
found = true;
// Exclude the line containing the password
while (getline(inFile, line) && line.find("Generated password:") == string::npos) {
cout << line << endl;
}
break;
}
}
inFile.close();

if (!found) {
cout << "User with National ID " << searchID << " not found.\n";
}

cout << "\nPress any key to continue...";
getch(); // Wait for a key press
admin(); // Return to admin options
}
int pub=0;
void public_result()
{
    system("color 0D");
    char choose;
    cout<<"Are you sure you want to public the voting results....??(y/n)"<<endl;
    cin>>choose;
    if(choose=='y')
    {
        pub++;
    }
}

void readVotingResults() {

    system("color 0E");
    if(pub>=1)
    {
    cout << "----------------------------------------\n";
    cout << " Current Voting Results\n";
    cout << "----------------------------------------\n";

   ifstream inFile("results.txt",ios::in);

    if (!inFile.is_open()) {
        cerr << "Error opening file: "<< endl;
        return;
    }

    string result;
    while (getline(inFile, result)) {
        cout << result << endl;
    }

    inFile.close();

    cout << "----------------------------------------\n";
    }
    else{
        cout<<" Voting results not published yet"<<endl;
    }
}
void saveresults(const vector<string>& positions, const vector<vector<string>>& candidates, const vector<int>& votes) {
ofstream file("results.txt", ios::out);
if (!file) {
cerr << "Error opening file for writing votes." << endl;
return;
}

for (size_t i = 0; i < positions.size(); ++i) {
        for (size_t j = 0; j < candidates[i].size(); ++j) {
            file << positions[i] << "_" << candidates[i][j] << ": " << votes[i * candidates[0].size() + j] << " votes " << endl;
        }
    }

file.close();
}
};

int main() {
System s1;

s1.displayWelcomeSlide();
return 0;
}