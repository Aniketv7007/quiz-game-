#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;
string player_name;
bool pay_half_skip = true;
bool skip = true;
long cash = 0;
long question_price = 100;
int consecutive = 0;
int right_answer = 0;
int wrong_answer = 0;
int question_no = 1;
void result();
void game_rules();
void ask_random_question();
void check_answer(char answer, char correct_answer);
struct question
{
    string question;
    string option_a;
    string option_b;
    string option_c;
    string option_d;
    char answer;
    bool availability;
};
question questions[10];

int main()
{
    system("cls");
    questions[0] = {"In which year the consituiton of india came into force..??? ", "26 January 1950", "26 January 1949 ", "26 November 1949 ", "15 August 1949", 'a', true};

    questions[1] = {"Shakkar river is tribute of which river in india..??", " Gomti river ", "Narmada river ", "Krishna river", "Godavari river ", 'b', true};

    questions[2] = {"Which of the following parts of THE HIMALAYAS is situated between Kali and Tista river ..?? ", "The Kumayun Himalaya", "The Himdari Himalaya", "The Himachal Himalaya", "The Central Himalaya", 'd', true};

    questions[3] = {"Whose proposed the idea of fresh water under Antartic ice sheets..??", "Russian scientist", "American scientist", "India scientist", "Irish scientist", 'a', true};

    questions[4] = {"Who was the chairman of NEP 2020 drafting committee..??", "Kailasavadivoo Sivan ", "Dr.K. Kasturirangan", "Prof. Yashpal Sharma ", "Prod.G. Rajagopal", 'b', true};

    questions[5] = {"Which college started the first COMPUTER SCIENCE ENGINEERING department in india ..?? ", "IIT BOMBAY ", "NIT TRICHY", "IIT  DELHI", "MNIT ALLAHABAD ", 'd', true};

    questions[6] = {"In indian currency notes RUPEE we see the picture of Mahatma Gandhi . Which year this photo of MAhatma Gandhi was taken..??", "1944", "1945", "1942", "1946", 'd', true};

    questions[7] = {"By which name the main branch of river Ganga is known as in BANGLADESH..?? ", "Jamuna", "Padma", "Meghana", "Kalindi", 'b', true};

    questions[8] = {"Who among the following is the author of INDICA..?? ", "Ashoka", "Chankya", "Megasthenes", "Seleucus", 'c', true};

    questions[9] = {"In which city of india 90 percent  of world's small diamond processed..?? ", "Baroda", "Mumbai", "Surat", "Jaipur", 'c', true};

    cout << "====================================================================================================================================" << endl;

    cout << "============================================== WELCOME  TO THE  ====================================================================" << endl;

    cout << "========================================== KAUN BANEGA KARORAPTI GAME SHOW  ========================================================" << endl;

    cout << "====================================================================================================================================" << endl;

    cout << "ENTER YOUR NAME :";

    getline(cin, player_name);

    system("cls");

    game_rules();

    while (true)
    {
        if (question_no > 10)
            break;

        ask_random_question();
    }
    result();
    return 0;
}
void ask_random_question()
{
    srand(time(0));

    while (true)
    {
        system("cls");
        int number = rand() % 10;
        if (questions[number].availability)
        {
            questions[number].availability = false;
            cout << "====================================================================================================================================" << endl;

            cout << "========================================== KAUN BANEGA KARORAPTI GAME SHOW  ========================================================" << endl;

            cout << endl;

            cout << "THIS QUESTION NO :" << question_no << " Is for $" << question_no << "\t\t\t\tBalance Is $" << cash << endl
                 << endl;

            cout << "LIFE LINE :";
            if (pay_half_skip)
                cout << "\th=> PAY HALF AND SKIP";
            if (skip)
                cout << "\tl=> LEAVE QUESTION";

            cout << endl
                 << endl;

            cout << "=================================================================================================================================" << endl;

            cout << "==================================================== CHOOSE YOUR OPTION  ========================================================" << endl;

            cout << questions[number].question << endl
                 << endl;

            cout << "a) " << questions[number].option_a << "\t\tb" << questions[number].option_b << endl
                 << endl;

            cout << "c) " << questions[number].option_c << "\t\td" << questions[number].option_d << endl
                 << endl;

            char answer = _getch();

            answer = tolower(answer);

            cout << endl;

                    question_no++;

            check_answer(answer, questions[number].answer);
            break;
        }
    }
}

void check_answer(char answer, char correct_answer){
    if (answer == correct_answer){
        cout << "Congralutions ...! Your answer is right" << endl;
    cout << "You earned $" << question_price << endl;
    cout << "Press any key to continue..." << endl;
    _getch();
    right_answer++;
    consecutive++;

    cash = cash + question_price;
}
else if ((answer == 'h') && (pay_half_skip))
{
    cout << "You choose the life line 'PAY HALF AND SKIP' " << endl;
    cout << "You lose $" << question_price / 4 << endl;
    cout << "Press any ckey to continue..." << endl;
    _getch();
    cash = cash - (question_price / 4);

    pay_half_skip = false;
}
else if ((answer == 'l') && (skip))
{
    cout << "You choose the life line 'LEAVE QUESTION' " << endl;
    cout << "YOU LOSE $ 0 " << endl;
    cout << "Press any key to continue..." << endl;
    _getch();
    skip = false;
}
else
{
    cout << "SORRY...! Your answer is wrong ..." << endl;
    cout << "Your lose $" << question_price / 2 << endl;
    cout << "Press any key to continue..." << endl;
    _getch();
    wrong_answer++;
    consecutive = 0;
    cash = cash - (question_price / 2);
}
question_price = question_price * 2;
if (consecutive == 3)
    pay_half_skip = true;

if (consecutive == 5)
    skip == true;
}
void result()
{
    double percentage;
    percentage = right_answer * 10;
    system("cls");
    cout << "=================================================================================================================================" << endl;

    cout << "========================================================= RESULT ================================================================" << endl;

    cout << "=================================================================================================================================" << endl;

    cout << "Player Name : \t\t\t" << player_name << endl
         << endl;
    cout << "Right Answers : \t\t\t" << right_answer << endl
         << endl;
    cout << "Wrong Answers : \t\t\t" << wrong_answer << endl
         << endl;
    cout << "Average : \t\t\t" << percentage << "%" << endl
         << endl;
    if (cash >= 0)
        cout << "Winning Amount :\t\t\t$" << cash << endl
             << endl;
    else
        cout << "Loosing Amount : \t\t\t$" << cash << endl
             << endl;
    cout << "=================================================================================================================================" << endl;

    cout << "=========================================== THANKS FOR PLAYING THIS GAME  =======================================================" << endl;

    cout << "=================================================================================================================================" << endl;

    cout << "================================================= BY ANIKET / AMIR ==============================================================" << endl;

    cout << "=================================================================================================================================" << endl;

    cout << "============================================= PRESS ANY KEY TO CONTINUE =========================================================" << endl;

    cout << "=================================================================================================================================" << endl;
    _getch();
}
void game_rules(){
    cout << "=================================================================================================================================" << endl;
    cout << "============================================== RULE AND REGULATIONS =============================================================" << endl;
    cout << "=================================================================================================================================" << endl;
    cout <<"01. There Are Total Ten Question In This Game. "<< endl << endl;
    cout <<"02. There Are Two Life Lines Which You Can At Any Stage Of The Game "<< endl << ends;
    cout <<"03. Pay Half & Skip Means You Have To Pay 1/4 Percent Of Correct Question" <<endl <<endl;
    cout <<"04. Leave Question Means You Can Leave a Question Withour Any Deduction" <<endl << endl;
    cout <<"05. If You Attempt Three Concecutive Right Answers Pay Half And Skip Will Rescued"<< endl<< endl;
    cout <<"06. If You Attemp Five Concecutive Right Answers Leave Question Will Rescued "<<endl << endl;
    cout <<"07. After Every Question The Amount Of Question Will Double "<<endl << endl;
    cout <<"08. If The Answer Is Wrong Half Amount Of question Will Be Double " << endl << endl;
    cout <<"09. Press H For Pay Half & Skip Help Line And L For Leave Question Help LIne" << endl << endl;
    cout <<"10. Press A , B , C or D Answer Any Question" << endl << endl;
    cout << "=================================================================================================================================" << endl;
    cout << "===================================================== PRESS ANY KEY TO GET START ================================================" << endl;
    cout << "=================================================================================================================================" << endl;
    _getch();
}