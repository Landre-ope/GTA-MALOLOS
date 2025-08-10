#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <cctype>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

int mainMenuScreen ();
std::string usernameStore ();
std::string passwordStore ();
int usernameSearch (std::string username, std::string usernameList[]);
void banner();
//validate un and pw
bool validateUsername(string username);
bool validatePassword(string password);

//pangslow lang
void slowPrint(string text, int delay_ms = 100) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
    cout << endl;
}
//pangaano ng balance
void balanceMod (double balance[], int accNum);
void showAd();
//leaderboard
void showLeaderboard(string usernameList[], double balanceList[], int totalAccounts);

//pampaarte ng type ng pw

std::string getPasswordInput();

//GAMES SECTION
void cupRoyale (double balance[], int accNum);
void displayCupsClosed();
void displayCupsOpen(int ballPosition);
void luckyPick(double balance[], int accNum);
void UpDown(double balance[], int accNum);
void blackJack(double balance[], int accNum);
int drawCard();
void delay(int milliseconds) { Sleep(milliseconds); }
void showCoin(int side);
void suspenseToss();
void KaraKrus (double balance[], int accNum);

//start ng main func
int main (){
    std::string usernameList[20], passwordList[20];
    std::string username, password;
    int userCount = 0;
    bool keepGoing = true;
    double balanceList [20];
    fill (balanceList, balanceList + 20, 0);
    //fill (usernameList, usernameList + 20, "emptyUser"); 
    //eto balance namin HAHAHHAHAHA:
    balanceList [0] = 100000;
    balanceList [1] = -200;
    balanceList [2] = 666666;
    balanceList [3] = 6969;
    balanceList [4] = 911;
    balanceList [5] = -5;
    balanceList [6] = 12345;
    balanceList [7] = -20;
    balanceList [8] = 555;
    balanceList [9] = -1;
    //eto naman username:
    usernameList [0] = "vince123";
    usernameList [1] = "mariaanalangmalakas";
    usernameList [2] = "Ihatenaggers";
    usernameList [3] = "kennethutan";
    usernameList [4] = "nhiaggers";
    usernameList [5] = "just_in_4th";
    usernameList [6] = "crisostomoibarra";
    usernameList [7] = "jenriclang";
    usernameList [8] = "charmielagne";
    usernameList [9] = "posangmabangis";
    //eto naman password:
    passwordList [0] = "vince123";
    passwordList [1] = "12345678";
    passwordList [2] = "naggershater08";
    passwordList [3] = "brrbrrpatapim32";
    passwordList [4] = "bombafrica";
    passwordList [5] = "tungtugtugsahur";
    passwordList [6] = "NoliMeTangere";
    passwordList [7] = "jenriclang";
    passwordList [8] = "charlie";
    passwordList [9] = "posa123";

    int totalAcc = sizeof (usernameList)/sizeof (string);

    do{
    int optionMM = mainMenuScreen();
    int adminChoice;
    
        
    if (optionMM == 999){
        
        system ("cls");

        banner();

        int deleteAcc;
        std::string passcode;

        std::cout << "Welcome, Admin!\n\n";
        std::cout << "Enter passcode to continue: ";
        passcode = getPasswordInput();

        std::cout << "\nConfirming passcode";
        slowPrint("...", 1000);
        this_thread::sleep_for(chrono::milliseconds(500));

        if (passcode == "00000000"){
            do {
            system ("cls");

            banner();
            cout << "         +---------------------+\n";
            cout << "         |      Admin Menu     |\n";
            cout << "         +---------------------+\n\n";

            cout << "             1) Add Account\n";
            cout << "             2) Delete Account\n";
            cout << "             3) Modify Balance\n";
            cout << "             4) Exit\n";

            cout << "\nPlease enter your choice (1-3): ";
            cin >> adminChoice;
            
            if (adminChoice == 1){
                std::cout << "\nProceeding to Add Account Menu";
                slowPrint("...", 1000);
                this_thread::sleep_for(chrono::milliseconds(500));

                std::string adminAdd;
                do{   
                    system ("cls");
                    banner();
                    std::cout << "Here is the complete account list: \n\n";
                    for (int i = 0; i < 20; i++){
                        std::cout << "[" << i + 1 << "] " << usernameList[i] << std::endl;
                    }
                if (totalAcc < 20) {
                    std::cin.ignore(); // clear input buffer
                    std::cout << "\nEnter new username: ";
                    getline(std::cin, usernameList[totalAcc]);

                    std::cout << "Enter new password: ";
                    getline(std::cin, passwordList[totalAcc]);

                    balanceList[totalAcc] = 500;
                    totalAcc++;
                    std::cout << "\nAccount successfully added!\n";
                }
                else {
                    std::cout << "\nAccount limit reached. Cannot add more users.\n";
                }
                this_thread::sleep_for(chrono::milliseconds(1000));
                std::cout << "Add an account again? (y/n): ";
                std::cin >> adminAdd;
                    
                } while (adminAdd == "y");
                std::cout << "\nReturning to Admin Menu";
                slowPrint("...", 1000);
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            else if (adminChoice == 2){
                std::cout << "\nProceeding to Delete Account Menu";
                slowPrint("...", 1000);
                this_thread::sleep_for(chrono::milliseconds(500));

                std::string adminDel;
                do{
                    
                    system ("cls");
                    banner();
                    std::cout << "Here is the complete account list: \n\n";
                    for (int i = 0; i < 20; i++){
                        std::cout << "[" << i + 1 << "] " << usernameList[i] << std::endl;
                    }
                    std::cout << std::endl;
                    std::cout << "Enter account number to delete: ";
                    std::cin >> deleteAcc;

                    deleteAcc--; // Adjust for 0-based index
                    if (deleteAcc >= 0 && deleteAcc < totalAcc) {
                        for (int i = deleteAcc; i < totalAcc - 1; i++) {
                            usernameList[i] = usernameList[i + 1];
                            passwordList[i] = passwordList[i + 1];
                            balanceList[i] = balanceList[i + 1];
                        }
                        totalAcc--;
                        std::cout << "\nAccount successfully deleted.\n";
                    } else {
                        std::cout << "\nInvalid account number.\n";
                    }
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    std::cout << "Delete an account again? (y/n): ";
                    std::cin >> adminDel;
                    
                } while (adminDel == "y");
                std::cout << "\nReturning to Admin Menu";
                slowPrint("...", 1000);
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            else if (adminChoice == 3){
                int modifyBal;
                char adminMod;
                double repBal;
                std::cout << "\nProceeding to Modify Balance Menu";
                slowPrint("...", 1000);
                this_thread::sleep_for(chrono::milliseconds(500));

                std::string adminDel;
                do{
                    
                    system ("cls");
                    banner();
                    std::cout << "Here is the complete account list: \n\n";
                    for (int i = 0; i < 20; i++){
                        std::cout << "[" << i + 1 << "] " << usernameList[i] << std::endl;
                    }
                    std::cout << std::endl;
                    std::cout << "Enter account number to modify: ";
                    std::cin >> modifyBal;

                    //std::cout << "You've chosen '" << usernameList [modifyBal - 1] << "'. Do you confirm? (y/n): ";
                    //std::cin >> confirmation;
                    std::cout << "\nUser '" << usernameList [modifyBal - 1] << "' currently have $" << balanceList[modifyBal - 1] << ".\n";
                    std::cout << "Enter new balance to replace: $";
                    std::cin >> repBal;
                    balanceList[modifyBal - 1] = repBal;
                    std::cout << "\nAccount balance successfully modified.\n";
                    
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    std::cout << "Modify an account again? (y/n): ";
                    std::cin >> adminMod;
                    
                } while (adminMod == 'y');
                std::cout << "\nReturning to Admin Menu";
                slowPrint("...", 1000);
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            } while (adminChoice != 4);
        }
        else {
            std::cout << "Invalid passcode. Returning to Main Menu";
            slowPrint("...", 1000);
            this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }
        std::cout << "Returning to Main Menu";
        slowPrint("...", 1000);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    else if (optionMM == 1){
        system ("cls");

        banner();

        std::cout << "LOGIN\n\n";

        std::cout << "Enter username: ";
        std::cin >> username;
        int valid = usernameSearch(username, usernameList);
        if (valid == -1) {
            std::cout << "\nUser does not exist";
            slowPrint("...", 1000);
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        else {
            std::cout << "Hello, " << username << "! Please enter your password: ";
            password = getPasswordInput();
            std::cout << "\nLogging in";
            slowPrint("...", 1000);
            this_thread::sleep_for(chrono::milliseconds(500));
            if (passwordList[valid] == password) {
                int gameOption, accNum = valid;
                do {
                    system ("cls");
                    banner();
                    std::cout << "Welcome!\n\n";
                    std::cout << "Balance = $" << balanceList[valid] << "\n\n";
                    cout << "[1] Cup Royale\n";
                    cout << "[2] Lucky Pick\n";
                    cout << "[3] Up or Down\n";
                    cout << "[4] Blackjack\n";
                    cout << "[5] Kara Krus\n";
                    cout << "[6] Manage Balance\n";
                    cout << "[7] Leaderboard\n";
                    cout << "[8] Logout\n";
                    do {
                        std::cout << "\nEnter option: ";
                        std::cin >> gameOption;

                        switch (gameOption) {
                        case 1:
                            std::cout << "\nOpening Cup Royale";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            cupRoyale(balanceList, accNum);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        case 2:
                            std::cout << "\nOpening Lucky Pick";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            luckyPick(balanceList,accNum);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        case 3:
                            std::cout << "\nOpening Up or Down";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            UpDown(balanceList,accNum);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        case 4:
                            std::cout << "\nOpening Blackjack";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            blackJack(balanceList,accNum);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                        break;
                        case 5:
                            std::cout << "\nOpening Kara Krus";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            KaraKrus(balanceList, accNum);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        case 6:
                            std::cout << "\nOpening Balance Section";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            balanceMod(balanceList,accNum);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        case 7:
                            std::cout << "\nOpening Leaderboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            showLeaderboard(usernameList, balanceList, totalAcc);
                            std::cout << "\nReturning to Dashboard";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        case 8:
                            std::cout << "\nLogging out";
                            slowPrint("...", 1000);
                            this_thread::sleep_for(chrono::milliseconds(500));
                            break;
                        default:
                            std::cout << "Invalid option. Try again.\n";
                            break;
                        }
                    } while (gameOption < 1 || gameOption > 8);
                } while (gameOption != 8);
            }
            else std::cout << "Invalid password.";
            this_thread::sleep_for(chrono::milliseconds(3000));
        }


    }
    else if (optionMM == 2){
        if (userCount < 10){  
            usernameList [userCount + 10] = usernameStore();
            passwordList [userCount + 10] = passwordStore();
            std::cout << "\nRegistration successful!\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
            balanceList [userCount + 10] = 500;
            userCount += 1;
        }
        else std::cout << "Sorry, the server is already full.";
        std::cout << "\nGoing back to homescreen";
        slowPrint("...", 1000);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    else keepGoing = false;
    } while (keepGoing);
} //end ng main func

void banner() {
    std::cout << " ___  _____ _____                 _         _  " << std::endl;
    std::cout << "(  _`(_   _(  _  )   /'\\_/`\\     (_ )      (_ )" << std::endl;
    std::cout << "| ( (_)| | | (_) |   |     |  _ _ | |   _   | |   _    ___ " << std::endl;
    std::cout << "| |___ | | |  _  |   | (_) |/'_` )| | /'_`\\ | | /'_`\\/',__)" << std::endl;
    std::cout << "| (_, )| | | | | |   | | | ( (_| || |( (_) )| |( (_) \\__, \\ " << std::endl;
    std::cout << "(____/'(_) (_) (_)   (__ (_`\\__,_(___`\\___/(___`\\_________/                    _     _____     _     _         _    " << std::endl;
    std::cout << "(  _`\\                ( )   (_ ) _                (_   _)                _    ( )   (  _  )   ( )   ( )_      ( )_ _" << std::endl;
    std::cout << "| ( (_)  _ _  ___ ___ | |_   | |(_) ___   ___       | |   _  ______  _ _(_)  _| |   | (_) |  _| |  _| (_)  ___| ,_(_)  _    ___" << std::endl;
    std::cout << "| |___ /'_` /' _ ` _ `| '_`\\ | || |/'_`\\ /'_`\\      | | /'_`(______/'_` | |/'_` |   |  _  |/'_` |/'_` | |/'___| | | |/'_`\\/' _ `\\ " << std::endl;
    std::cout << "| (_, ( (_| | ( ) ( ) | |_) )| || | ( ) ( (_) |     | |( (_) )    ( (_| | ( (_| |   | | | ( (_| ( (_| | ( (___| |_| ( (_) | ( ) |" << std::endl;
    std::cout << "(____/`\\__,_(_) (_) (_(_,__/(___(_(_) (_`\\__  |     (_)`\\___/'    `\\__,_(_`\\__,_)   (_) (_`\\__,_`\\__,_(_`\\____`\\__(_`\\___/(_) (_)" << std::endl;
    std::cout << "                                        ( )_) |                                                                                 " << std::endl;
    std::cout << "                                         \\___/'                                                                                 " << std::endl;

}

int mainMenuScreen() {
    system("cls"); 

    banner();

    //loading animation
    cout << "Loading menu";
    slowPrint("...", 300);
    this_thread::sleep_for(chrono::milliseconds(500));
    system("cls");

    banner(); 
    srand (time(0));
    int answer;

    cout << "Note: New users get free $500 balance.\n\n";

    cout << "         +---------------------+\n";
    cout << "         |      Main Menu      |\n";
    cout << "         +---------------------+\n\n";

    cout << "               1) Login\n";
    cout << "               2) Register\n";
    cout << "               3) Exit\n";

    cout << "\nPlease enter your choice (1-3): ";

    // Input validation
    while (!(cin >> answer) || answer < 1 || answer > 3) {
        if (answer == 999) break;
        cin.clear(); // clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "\nInvalid choice. Please enter 1, 2, or 3: ";
    }

    // Fun random tip
    cout << "\nTip of the Day: ";
    int tipNum = rand() % 6 + 1;
    switch (tipNum)
    {
    case 1:
        cout << "Luck favors the bold!\n";
        break;
    case 2:
        cout << "Think before you pull the trigger!\n";
        break;
    case 3: 
        cout << "Remember: No risk, no reward!\n";
        break;
    case 4:
        cout << "Momma didn't raise a quitter, stay winning!\n";
        break;
    case 5:
        cout << "Do not bet on black, they always steal your money.\n";
        cout << "- Landre\n";
    case 6:
        cout << "Always bet all your money for higher prizes.\n";
    default:
        break;
    }
    this_thread::sleep_for(chrono::milliseconds(2000)); // Small pause
    return answer;
}

std::string usernameStore (){
    system ("cls");

    banner();

    std::cout << "REGISTRATION\n\n";

    std::string username;
    bool valid = false;

    do {
        std::cout << "Enter username: ";
        std::getline(std::cin >> std::ws, username);

        valid = validateUsername(username);

        if (!valid) {
            cout << "Please try again.\n\n";
        }
    } while (!valid);

    return username;
};

std::string passwordStore (){
    std::string password, password2;
    bool valid = false, same = false;

    do{
        do {
            std::cout << "Enter password: ";
            password = getPasswordInput();
            //std::getline(std::cin >> std::ws, password);

            valid = validatePassword(password);

            if (!valid) {
                cout << "Please try again.\n\n";
            }
        } while (!valid);
        std::cout << "Confirm password: ";
        password2 = getPasswordInput();

        if (password == password2) same = true;
        else {
            std::cout << "\nThe passwords do not match, try again.\n\n";
        }
    } while (!same);
    

    return password;
};

int usernameSearch (std::string username, std::string usernameList[]){
    for (int i = 0; i < 20; i++){
        if (username == usernameList[i]) return i;
    }
    return -1;
};

//VALIDATE USERNAME AND PASSWORD

bool validateUsername(string username) {
    if (username.length() < 4 || username.length() > 12) {
        cout << "\nUsername must be between 4 and 12 characters long.\n";
        return false;
    }
    for (char c : username) {
        if (!isalnum(c)) { // only letters and numbers
            cout << "\nUsername can only contain letters and numbers (no spaces or symbols).\n";
            return false;
        }
    }
    return true;
}

bool validatePassword(string password) {
    if (password.length() < 6 || password.length() > 16) {
        cout << "\nPassword must be between 6 and 16 characters long.\n";
        return false;
    }
    for (char c : password) {
        if (isspace(c)) {
            cout << "\nPassword cannot contain spaces.\n";
            return false;
        }
    }
    return true;
}
//leaderboard
void showLeaderboard(string usernameList[], double balanceList[], int totalAccounts) {
    system("cls");
    banner();
    cout << "=========== LEADERBOARD ===========\n";
    cout << left << setw(20) << "Username" << setw(10) << "Balance\n";
    cout << "-----------------------------------\n";

    // Copy original balances and usernames to sort without modifying the original
    string tempUsernames[totalAccounts];
    double tempBalances[totalAccounts];

    for (int i = 0; i < totalAccounts; ++i) {
        tempUsernames[i] = usernameList[i];
        tempBalances[i] = balanceList[i];
    }

    // Sort by balance (simple bubble sort)
    for (int i = 0; i < totalAccounts - 1; ++i) {
        for (int j = i + 1; j < totalAccounts; ++j) {
            if (tempBalances[j] > tempBalances[i]) {
                swap(tempBalances[i], tempBalances[j]);
                swap(tempUsernames[i], tempUsernames[j]);
            }
        }
    }

    // Show top 5 or fewer
    int displayCount = min(7, totalAccounts);
    for (int i = 0; i < displayCount; ++i) {
        cout << left << setw(20) << tempUsernames[i] << "$" << fixed << setprecision(2) << tempBalances[i] << "\n";
    }
    cout << "...\n";
    for (int i = 17; i < totalAccounts; ++i) {
        cout << left << setw(20) << tempUsernames[i] << "$" << fixed << setprecision(2) << tempBalances[i] << "\n";
    }

    cout << "\nPress any key to return to the menu... ";
    cin.ignore();
    cin.get();
}

//pangaano ng balance
void balanceMod (double balance[], int accNum){
    bool keepGoing = true;
    while (keepGoing){
        system("cls");
        banner();
        int balanceOption;

        std::cout << "======= WELCOME TO BALANCE SECTION =======\n\n";
        std::cout << "Current balance: $" << balance[accNum] << "\n\n";
        
        std::cout <<"Select an Action:\n";
        std::cout << "[1] Watch an Ad\n";
        std::cout << "[2] Return to Main Menu\n";
        std::cout << "Enter: ";
        std::cin >> balanceOption;

        if (balanceOption == 1){
            balance[accNum] += 50;
            showAd();
            std::cout << "\n$50 has been credited to your account";
            slowPrint("...", 1000);
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        else keepGoing = false;
    }
}
void showAd() {
    string ads[] = {
        "[AD] Feeling poor in-game and in life? Try 'Walis Tamis': the only broom that sweeps your debt away!",
        "[AD] Tired of being unlucky? Try 'Swerte Cologne'  one spray and you're suddenly top 1!",
        "[AD] Download *Tambay Simulator* now and experience the thrill of doing absolutely nothing!",
        "[AD] Order now at 'Mang Cardo's BBQ' the only BBQ with +5 Luck buff!",
        "[AD] Looking for love? Download *Tindig* Swipe left, right, or up to increase your stats!",
        "[AD] Join 'Bet Mo 'To Online Casino'! Real losses, fake winnings guaranteed!",
        "[AD] Use promo code 'PAWA50' to get 50% more kuryente. Only from *Meralcool*!",
        "[AD] Invest in BitKangkong the newest crypto that grows in dirty water!",
        "[AD] Drink *Kapeng Walang Gising* matutulog ka habang nagkakape!",
        "[AD] You're watching: '101 Ways to Waste Time Season 3, Episode 14: Watching Fake Ads!'"
    };

    srand(time(0));
    int index = rand() % 10;

    slowPrint("\nNow playing ad...\n", 100);
    this_thread::sleep_for(chrono::milliseconds(500));
    slowPrint(ads[index], 50);
    this_thread::sleep_for(chrono::milliseconds(1500));
}


//PAMPAARTE NG TYPE SA PW

std::string getPasswordInput() {
    std::string password;
    char ch;

    while (true) {
        ch = _getch(); // Read a single character

        if (ch == 13) { // Enter key
            cout << endl;
            break;
        } else if (ch == 8) { // Backspace key
            if (!password.empty()) {
                cout << "\b \b"; // Move back, erase *, move back again
                password.pop_back();
            }
        } else if (isprint(ch)) { // If printable character
            password += ch;
            cout << '*';
        }
    }

    return password;
}

//GAMES SECTION

void displayCupsClosed() {
    cout << "    ___      ___      ___\n";
    cout << "   /   \\    /   \\    /   \\\n";
    cout << "  /     \\  /     \\  /     \\\n";
    cout << " |       ||       ||       |\n";
    cout << " |   1   ||   2   ||   3   |\n";
    cout << " |_______||_______||_______|\n";
}

// Function to display cups opened and show where the ball is
void displayCupsOpen(int ballPosition) {

    cout << "\n";

    cout << "    ___      ___      ___\n";
    cout << "   /   \\    /   \\    /   \\\n";
    cout << "  /     \\  /     \\  /     \\\n";
    cout << " |       ||       ||       |\n";
    cout << " |   1   ||   2   ||   3   |\n";
    cout << " |_______||_______||_______|\n";

    for (int i = 1; i <= 3; ++i) {
        cout << "   ";
        if (i == ballPosition)
            cout << " (o) ";
        else
            cout << "\t";
    }
}

void cupRoyale(double balance[], int accNum) {
    char playAgain = 'y';
    srand(time(0)); // Seed random once

    while (playAgain == 'y' || playAgain == 'Y') {
        system("cls");
        banner();

        cout << "======= WELCOME TO CUP ROYALE! =======\n\n";
        cout << "Rules:\n";
        cout << "- Guess which cup (1-3) hides the ball.\n";
        cout << "- Win 2x your bet if you guess correctly.\n\n";

        cout << "Current balance: $" << balance[accNum] << "\n\n";

        double bet;
        cout << "Enter your bet amount: $";
        cin >> bet;

        while (bet > balance[accNum] || bet <= 0) {
            cout << "Invalid bet. Please enter a valid amount within your balance: ";
            cin >> bet;
        }

        balance[accNum] -= bet; // Deduct bet immediately

        int ballPosition = rand() % 3 + 1; // Random ball position (1-3)
        int playerChoice;

        displayCupsClosed();

        cout << "\nChoose a cup (1-3): ";
        cin >> playerChoice;

        while (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Please choose between 1 and 3: ";
            cin >> playerChoice;
        }

        cout << "\nLifting the cups";
        slowPrint("...", 1000);
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\n\n";

        displayCupsOpen(ballPosition);

        cout << "\n\nThe ball was under cup #" << ballPosition << "!\n";

        if (playerChoice == ballPosition) {
            double winnings = bet * 2;
            balance[accNum] += winnings;
            cout << "Congratulations! You found the ball and won $" << winnings << "!\n";
        } else {
            cout << "Oops! Better luck next time. You lost $" << bet << ".\n";
        }

        cout << "\nCurrent balance: $" << balance[accNum] << "\n";
        cout << "\nDo you want to play Cup Royale again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing Cup Royale!\n";
    this_thread::sleep_for(chrono::milliseconds(500));
}


void luckyPick(double balance[], int accNum) {
    char playAgain = 'y';
    srand(time(0)); // Random seed once

    while (playAgain == 'y' || playAgain == 'Y') {
        system("cls");
        banner();

        cout << "======= WELCOME TO LUCKY PICK! =======\n\n";
        cout << "Rules:\n";
        cout << "- Guess a number between 1 and 10.\n";
        cout << "- You have up to 3 chances.\n";
        cout << "- Prize depends on which attempt you guess correctly:\n";
        cout << "    First guess  = 5x payout!\n";
        cout << "    Second guess = 3x payout!\n";
        cout << "    Third guess  = 2x payout!\n\n";

        cout << "Current balance: $" << balance[accNum] << "\n\n";

        double bet;
        cout << "Enter your bet amount: $";

        while (!(cin >> bet) || bet > balance[accNum] || bet <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid bet. Please enter a valid amount within your balance: $";
        }  

        balance[accNum] -= bet; 
        int secretNumber = rand() % 10 + 1;
        bool win = false;
        int attemptWon = 0;

        for (int i = 1; i <= 3; i++) {
            int userGuess;
            cout << "\nGuess #" << i << ": ";
            cin >> userGuess;

            while (userGuess < 1 || userGuess > 10) {
                cout << "Number must be between 1 and 10. Try again: ";
                cin >> userGuess;
            }

            if (userGuess == secretNumber) {
                win = true;
                attemptWon = i;
                break;
            } else {
                if (userGuess > secretNumber)
                    cout << "Too high!\n";
                else
                    cout << "Too low!\n";

                if (i < 3)
                    cout << "Try again...\n";
            }
        }

        cout << "\nThe lucky number was: " << secretNumber << "!\n";

        if (win) {
            double winnings = 0;
            if (attemptWon == 1) winnings = bet * 5;
            else if (attemptWon == 2) winnings = bet * 3;
            else if (attemptWon == 3) winnings = bet * 2;

            balance[accNum] += winnings;
            cout << "\nCongratulations! You won $" << winnings << " on attempt #" << attemptWon << "!\n";
        } else {
            cout << "\nOh no! You used all your guesses. You lost $" << bet << ".\n";
        }

        cout << "\nCurrent balance: $" << balance[accNum] << "\n";

        cout << "\nDo you want to play Lucky Pick again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing Lucky Pick!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void UpDown(double balance[], int accNum) {
    srand(time(0));
    int play = 1;

    system("cls");
    banner();

    cout << "====== WELCOME TO GUESS UP OR DOWN ======\n";
    cout << "Rules: You're gonna get a random number from 1-12.\n";
    cout << "You need to guess if the next number is higher or lower.\n";
    cout << "Choose the risk multiplier. Equal number = draw.\n\n";

    while (play == 1) {
        double bet;
        cout << "Current balance: $" << balance[accNum] << "\n";
        cout << "Enter bet: $";
        cin >> bet;

        if (bet <= 0 || bet > balance[accNum]) {
            cout << "Invalid bet. Try again.\n";
            continue;
        }

        int gue = rand() % 12 + 1;
        cout << "\nYour number is: " << gue << endl;

        int choice;
        cout << "[1] Up\n[2] Down\nYour guess: ";
        while (!(cin >> choice) || (choice < 1 || choice > 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Choose 1 or 2: ";
        }

        int riskLevel;
        cout << "\nChoose risk level:\n";
        cout << "1. Safe (+0.3x win, -0.5x loss)\n";
        cout << "2. Risky (+0.7x win, -1.0x loss)\n";
        cout << "3. Insane (+1.5x win, -2.0x loss)\n";
        cout << "Your choice: ";
        cin >> riskLevel;

        float winMultiplier = 0.3, lossMultiplier = 0.5;
        switch (riskLevel) {
            case 2: winMultiplier = 0.7; lossMultiplier = 1.0; break;
            case 3: winMultiplier = 1.5; lossMultiplier = 2.0; break;
            case 1:
            default: break;
        }

        cout << "Spinning";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << "\n";

        int newgue = rand() % 12 + 1;
        cout << "New number is: " << newgue << "\n";

        if (newgue == gue) {
            cout << "It's a draw! No change.\n";
        } else if ((choice == 1 && newgue > gue) || (choice == 2 && newgue < gue)) {
            double winnings = bet * winMultiplier;
            balance[accNum] += winnings;
            cout << "You won! Gained $" << winnings << "\n";
        } else {
            double loss = bet * lossMultiplier;
            balance[accNum] -= loss;
            cout << "You lost! Lost $" << loss << "\n";
        }

        cout << "Current balance: $" << balance[accNum] << "\n";

        if (balance[accNum] < 1) {
            cout << "\nYou're broke. Come back when you have money.\n";
            break;
        }

        cout << "Press 1 to play again, any other key to exit: ";
        cin >> play;
    }

    cout << "\nThanks for playing, now go touch grass, what a loser hahaahahhaah\n";
}


int drawCard() {
    return rand() % 11 + 1;
}

void blackJack(double balance[], int accNum) {
    srand(static_cast<unsigned int>(time(0)));
    bool proceedGame = true;

    system ("cls");
    banner();

    cout << "============== BLACKJACK! ==============\n\n";
    slowPrint("Welcome to Blackjack!" , 20);
    slowPrint("Your goal is to get as close to 21 as possible without going over.", 20);
    slowPrint("You start with two cards and can choose to hit or stand.", 20);
    slowPrint("If you go over 21, you bust and lose the round.", 20);
    slowPrint("The dealer draws until reaching 17 or higher.", 20);
    slowPrint("Whoever is closer to 21 wins.\n", 20);

    cout << "Current balance: $" << balance[accNum] << "\n\n";

    double bet;
    cout << "Enter your bet amount: $";

    while (!(cin >> bet) || bet > balance[accNum] || bet <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid bet. Please enter a valid amount within your balance: $";
    } 
    balance[accNum] -= bet; 

    int playerTotal = drawCard() + drawCard();
    int dealerTotal = drawCard() + drawCard();

    cout << "Your starting total: " << playerTotal << "\n";

    string choice;
    while (true) {
        cout << "Do you want to 'hit' or 'stand'? ";
        cin >> choice;

        if (choice == "hit") {
            int card = drawCard();
            playerTotal += card;
            cout << "\nYou drew a " << card << ". Your new total is " << playerTotal << ".\n";

            if (playerTotal > 21) {
                cout << "\nYou busted! Dealer wins.\n";
                proceedGame = false;
                break;
            }
        } else if (choice == "stand") {
            break;
        } else {
            cout << "Invalid choice. Please type 'hit' or 'stand'.\n";
        }
    }

    while (proceedGame){
    slowPrint("\nDealer's turn...\n", 75);
    cout << "Dealer's starting total: " << dealerTotal << "\n";

    while (dealerTotal < 17) {
        int card = drawCard();
        dealerTotal += card;
        cout << "Dealer draws a " << card << ". Total is now " << dealerTotal << ".\n";
    }

    cout << "Final Totals -> Player: " << playerTotal << " | Dealer: " << dealerTotal << "\n";

    if (dealerTotal > 21 || playerTotal > dealerTotal) {
        cout << "Player wins! You win $" << bet << ".\n";
        balance[accNum] += bet * 2;
    } else if (playerTotal < dealerTotal) {
        cout << "Dealer wins! You lose $" << bet <<".\n";
    } else {
        cout << "\nIt's a tie! Your bet is returned.\n";
        balance[accNum] += bet;
    }
    proceedGame = false;
    }
    cout << "Current balance: $" << balance[accNum] << "\n\n";
}

int tossCoin() {
    return rand() % 2; // 0 = heads, 1 = tails
}

void showCoin(int side) {
    cout << "+---------+" << endl;
    if (side == 0)
        cout << "|  HEADS  |" << endl;
    else
        cout << "|  TAILS  |" << endl;
    cout << "+---------+" << endl;
}

void suspenseToss() {
    cout << "\nTossing the coins";
    for (int i = 0; i < 3; i++) {
        cout << "." << flush;
        delay(500); 
    }
    cout << endl;
    delay(700); 
}

void KaraKrus(double balance[], int accNum) {
    int betChoice;
    int betAmount;
    char playAgain;

    srand(time(0));

    do {
        system("cls");
        banner();
        cout << "======Sali ka Kara Krus?======\n\n" << endl;
        cout << "Current balance: $" << balance[accNum] << "\n\n";

        cout << "Place your bet (0 = heads, 1 = tails): ";
        cin >> betChoice;

        cout << "Enter your bet amount: ";
        while (!(cin >> betAmount) || betAmount > balance[accNum] || betAmount <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid bet. Please enter a valid amount within your balance: $";
        }  

        balance[accNum] -= betAmount;

        int coin1, coin2;

        do {
            suspenseToss();

            coin1 = tossCoin();
            coin2 = tossCoin();

            cout << "\nCoin 1:" << endl;
            delay(1000); 
            showCoin(coin1);

            delay(1200); 
            cout << "Coin 2:" << endl;
            delay(1000);
            showCoin(coin2);

            if (coin1 != coin2) {
                cout << "\nIt's a mix! Tossing again...\n" << endl;
                delay(1500); 
            }

        } while (coin1 != coin2);

        // Outcome
        if (coin1 == betChoice) {
            cout << "\nNice oi! You earned " << betAmount * 2 << "!" << " " << "May pangpa-hair transplant na." << endl;
            balance[accNum] += (betAmount * 2);
        } else {
            cout << "\nYou lose! You lost your " << betAmount << " na pambili ng maintenance sa highblood." << endl;
        }

        // Replay option
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "Pabarya ka na ulit para makapaglaro pa tayo ah?" << endl;
}