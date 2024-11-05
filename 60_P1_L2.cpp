#include <iostream>
#include <vector>

using namespace std;

enum enItemsGam
{
    Peaper = 1,
    Stone = 2,
    Scissor = 3
};

int rand_num_role(int from, int to)
{

    int num = rand() % (to - from + 1) + from;

    return num;
}

int user_inputs(string message)
{
    int count_role = 0;

    do
    {
        cout << message << endl;
        cin >> count_role;
    } while (count_role < 0 || count_role > 10);

    return count_role;
}

void result_role(pair<int, pair<int, int>> points, int user, int computer)
{
    string ItemsGam[3] = {"Peaper", "Stone", "Scissor"};

    cout << "------------------------------------------\n\n";
    cout << "Player1 Choice : " << ItemsGam[user - 1] << "\n";     // 1
    cout << "Computer Choice: " << ItemsGam[computer - 1] << "\n"; // 1

    if (points.second.first > points.second.second)
    {
        cout << "Round Winner : Player 1\n";
    }
    else if (points.second.first < points.second.second)
    {
        cout << "Round Winner : Computer\n";
    }
    else if (points.second.first == points.second.second)
    {
        cout << "Round Winner : [No Winner]" << "\n"
             << endl;
    }
    cout << "------------------------------------------\n";
}

void final_result_roles(pair<int, pair<int, int>> result, int count_role)
{
    cout << "------------------------------------------\n";
    cout << "------------ +++ Game Over +++ -----------" << "\n";
    cout << "------------------------------------------\n";
    cout << "------------- [ Game Results ] -----------\n\n";
    cout << "Game Rounds\t\t: " << count_role << "\n";
    cout << "Player1 won times\t: " << result.second.first << "\n";
    cout << "Computer won times\t: " << result.second.second << "\n";
    cout << "Draw times\t\t: " << result.first << "\n";
    if (result.second.first > result.second.second)
    {
        cout << "Final Winner\t\t: " << "Player1" << "\n\n";
    }
    else if (result.second.first < result.second.second)
    {
        cout << "Final Winner\t\t: " << "Computer" << "\n\n";
    }
    else
    {
        cout << "Final Winner\t\t: " << "No Winner" << "\n\n";
    }
    cout << "------------------------------------------\n\n";


}

bool check_Yes_or_No(string message)
{
    bool YesOrNo;

    cout << message;
    cin >> YesOrNo;

    return YesOrNo;
}

pair<int, pair<int, int>> game_result(int user, int computer)
{
    pair<int, pair<int, int>> points;
    // ورقة  1
    // حجر 2
    // مقص 3

    if (user == enItemsGam::Peaper && computer == enItemsGam::Stone)
    {
        points.second.first++;
    }
    else if (user == enItemsGam::Stone && computer == enItemsGam::Scissor)
    {
        points.second.first++;
    }
    else if (user == enItemsGam::Scissor && computer == enItemsGam::Peaper)
    {
        points.second.first++;
    }
    else if (user == computer)
    {
        points.first++;
    }
    else
    {
        points.second.second++;
    }

    return points;
}

void roles(int count_role)
{
    pair<int, pair<int, int>> result;
    pair<int, pair<int, int>> points;
    int user = 0;
    int computer = 0;

    for (int i = 0; i < count_role; i++) // 3
    {
        cout << "Role [" << i + 1 << "] begins :\n";
        do
        {
            user = user_inputs("Your Choice: [1]: Paper, [2]Stone: , [3]:Scissors?"); // 2
        } while (user > 3);
        computer = rand_num_role(enItemsGam::Peaper, enItemsGam::Stone); // 2
        points = game_result(user, computer);
        cout << "---------- Role [" << i + 1 << "] ----------\n";
        result_role(points, user, computer);
        result.first += points.first;
        result.second.first += points.second.first;
        result.second.second += points.second.second;
        points;
    }

    final_result_roles(result, count_role);
}

void game()
{
    bool YesOrNo = true;
    do
    {
        int count_role = user_inputs("How Many Rounds 1 to 10?");

        roles(count_role);

        YesOrNo = check_Yes_or_No("Do you want to play again ? [0]:No, or [1]:Yes? : "); 

    } while (YesOrNo != false);
}

int main()
{

    srand((unsigned)time(NULL));

    game();

    return 0;
}