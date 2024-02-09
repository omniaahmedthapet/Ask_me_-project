#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
struct user {
    int Id;
    string Name, Password, Email;
};
struct Questions {
    int ID_Questions, from, to;
    string questions;
};
struct Answer
{
    int ID_Questions;
    string answer;
};


int id_curr = 0;
Questions ge;
class Data
{
protected:
    vector<user>User;
    vector<Questions>que;
    vector<Answer>ans;
public:
    user in;
    void App_data(user in)
    {
        cleear();
        fstream users;
        users.open("users_data.txt", ios::out | ios::app);
        users << in.Id << "\n";
        users << in.Name << "\n";
        users << in.Email << "\n";
        users << in.Password << "\n";
        users.close();

    }
    void lines_data()
    {
        fstream users;
        users.open("users_data.txt", ios::in);
        int count_line = 0;
        string s;
        while (getline(users, s))
        {
            if (count_line % 4 == 0)
            {
                in.Id = stoi(s);

            }
            else if (count_line % 4 == 1)
            {
                in.Name = s;

            }
            else if (count_line % 4 == 2)
            {
                in.Email = s;

            }
            else {
                in.Password = s;
                User.push_back(in);


            }
            count_line++;
        }
        users.close();
    }
    void Input()
    {
        cleear();
        bool ch_Id = 0;
        user in1;
        cout << "Enter your ID" << " ";
        cin >> in1.Id;

		if (in1.Id < 0)
		{
            cout<<"Error\n";
			ch_Id = 0;
            Input();
            return ;


		}
		else
		{
			for (int i = 0; i < User.size(); i++)
			{
				if (in1.Id == User[i].Id)
				{
					cout << "The ID already exists\n";
					ch_Id = 0;
                    Input();
                    return ;
				}
			}
        }

        cout << "Enter your name" << " ";
        cin >> in1.Name;
        cout << "Enter your Email" << " ";
        cin >> in1.Email;
        cout << "Enter your Password" << " ";
        cin >> in1.Password;
        App_data(in1);
        id_curr = in1.Id;
    }
    void sign_in()
    {
        cleear();
        string email; int i = 0; bool check = 0; string password; string id;
        cout << "Enter your Email" << "\n";
        cin >> email;
        while (i < User.size())
        {
            if (email == User[i].Email)
            {
                check = 1;
                break;
            }
            i++;
        }

        if (check == 1)
        {
            cout << "enter your passward\n";
            cin >> password;
            if (User[i].Password == password)
                cout << "The password is correct";
            else
            {
                cout << "your passward is wrong\n";
                first_menu();
                int n; cin >> n;
                if (n == 1)
                {
                    Input();
                    return;
                }
                else if (n == 2)
                {
                    sign_in();
                    return;
                }

            }

        }

        else
        {
            cout << "This user does not exist ::";
            sign_in();
        }

        while (i < User.size())
        {
            if (email == User[i].Email)
            {
                id_curr = User[i].Id;
                break;

            }
            i++;
        }


    }
    void first_menu()
    {
        cout << " Enter 1 to sign up\n Enter 2 to sign in\n";
        cout << " Enter 3 to end the program\n";
    }

    void list()
    {
        cout << " Enter:\n";
        cout << " 1- Press 1 to view your questions\n";
        cout << " 2- Press 2 to view the questions you asked\n";
        cout << " 3- Press 3 to ask a question\n";
        cout << " 4- press 4 to responed to a Question\n";
        cout << " 5- press 5 to listall the users in the systrem\n";
        cout << " 6- press 6 to delete a Question\n";
        cout << " 7- press 7 to see all Questions and answers\n";
        cout << " 0- press 0 to exit\n";
    }
    void show_users()
    {
        cleear();
        for (int i = 0; i < User.size(); i++)
        {
            cout << "user ID : " << User[i].Id << "\n";
            cout << "user name : " << User[i].Name << "\n";

        }
    }


    void users_without_curr()
    {
        cleear();
        for (int i = 0; i < User.size(); i++)
        {
            if (id_curr != User[i].Id)
            {
                cout << "id" <<" "<< User[i].Id << "\n";
                cout << "Name" <<" " <<User[i].Name << "\n";
            }

        }
    }

    void read_data()
    {
        int count__line = 0;
        fstream ques;
        ques.open("ques_data.txt", ios::in);

        string l;
        while (getline(ques, l))
        {
            if (count__line % 4 == 0)
            {
                ge.ID_Questions = stoi(l);

            }
            else if (count__line % 4 == 1)
            {
                ge.from = stoi(l);

            }
            else if (count__line % 4 == 2)
            {
                ge.to = stoi(l);

            }
            else {
                ge.questions = l;
                que.push_back(ge);


            }
            count__line++;
        }
        ques.close();

    }
    void read_ans()
   {
        Answer to ;
        int count__line = 0;
        fstream ques;
        ques.open("Answers_data.txt", ios::in);

        string l;
        while (getline(ques, l))
        {
            if (count__line % 4 == 0)
            {
               to.ID_Questions = stoi(l);
            }
            else if (count__line % 4 == 1)
            {
                to.answer = l;
                ans.push_back(to);

            }
            count__line++;
        }
        ques.close();

    }


    void cleear()
    {
        que.clear();
        User.clear();
        ans.clear();
        lines_data();
        read_data();
        read_ans();


    }



};



class Questions_Answer :public Data
{
    int count_qs = 1;
    protected:




public:

    void id_Qu()
    {
        cleear();

        Questions ob;
        ob.to; bool check = 0;
        cout << "Enter your id_question : \n";
        cin >> ob.to;

        for (int i = 0; i < User.size(); i++)
        {
            if (ob.to == User[i].Id && User[i].Id != id_curr)
            {
                cout << "Enter Your question ";
                cin.ignore();
                getline(cin, ob.questions);
                check = 1;
                break;


            }

        }
        if (check == 1)
        {
            cout << "User found";
            ob.from = id_curr;

            put_questions(ob);
        }
        else
        {
            cout << " This user does not exist";
            return;
        }

    }


    void put_questions(Questions ob)
    {
        int counter = 0;
        cleear();
        if (que.size())
        {
            counter= que[que.size() - 1].ID_Questions + 1;
        }
        else
        {
            counter = 1;
        }
        ob.ID_Questions = counter;
        fstream que;
        que.open("ques_data.txt", ios::out | ios::app);
        que << ob.ID_Questions << "\n";
        que << ob.from << "\n";
        que << ob.to << "\n";
        que << ob.questions << "\n";
        que.close();


    }
    void ID_test()
    {
        cleear();
        bool ch=0;
          for(int y=0 ; y<que.size();y++)
        {
            if (que[y].to==id_curr)
            {
                ch = true ;
            }
        }

         if (ch==false)
        {
            cout << "there are no questions ";
            return;
        }
        for(int i=0 ; i<que.size();i++)
        {
            if(que[i].to==id_curr)
            {
                cout<<que[i].ID_Questions << "\n";
                cout<<que[i].questions <<"\n";
            }
        }
    }
    void response()
    {
        cleear();
        ID_test();
        int id_qq=0;
        bool check = 0;
        int x = 0 ;
        bool ch = false;
        string l;
        Answer an;
        Questions ob;
       /* for(int y=0 ; y<que.size();y++)
        {
            if (que[y].to==id_curr)
            {
                ch = true ;
            }
        }

         if (ch==false)
        {
            cout << "there are no questions ";
            return;
        }*/
        cout<<"Enter Id question :";
        cin>> an.ID_Questions;
        if(que[x].ID_Questions!=an.ID_Questions||an.ID_Questions<0)
            {
                cout<<"no question\n";
            }
        for(int i=0 ; i<que.size();i++)
        {

            if (que[i].ID_Questions==an.ID_Questions&&id_curr==que[i].to)
            {
                cout<<"The identification process was completed successfully\n";
                cout<<"Enter your answer\n";
                 check=1;
            }
        }
            if(check==1)
            {
                cin.ignore();
                getline(cin, an.answer);
                fstream Answers;
                Answers.open("Answers_data.txt",ios::out | ios::app);
                Answers <<  an.ID_Questions<<"\n";
                Answers <<  an.answer<<"\n";
                Answers.close();
            }
            else
            {
                check=0;
                cout<<"This question does not exist";

            }
    }

     void qu_from()
    {
            cleear();
            int x =0 ;
bool ch=0;
      for(int y=0 ; y<que.size();y++)
        {
            if (que[y].from==id_curr)
            {
                ch = true ;
            }
        }

         if (ch==false)
        {
            cout << "there are no questions ";
            return;
        }

            for(int i=0 ; i<que.size();i++)
            {
                if(que[i].from==id_curr)
                {
                    cout<<que[i].ID_Questions << "\n";
                    cout<<que[i].questions <<"\n";
                }
               /*else if (que[i].from!=id_curr)
                {
                    cout <<"No questions asked \n";
                    list();
                    break;
                }*/

            }

    }
    void delete_Questions()
    {
        cleear();

        int k2 = 0;
        bool ch =false;
        bool check = 0;
        int x ;
         for(int y=0 ; y<que.size();y++)
        {
            if (que[y].from==id_curr)
            {
                ch = true ;
            }
        }

         if (ch==false)
        {
            cout << "there are no questions ";
            return;
        }

         qu_from();

        cout<<"Enter your ID : \n";
        cin >> x ;
        for(int i=0 ; i<que.size();i++)
        {
            if(que[i].ID_Questions==x&&id_curr==que[i].from)
            {
                 check = 1;
                 k2 = i;
                 break;

            }
        }

         if(check==1)
            {

            int coun = 0; bool t = 0;
                for (int i = 0; i < ans.size(); i++)
                {
                    if (x== ans[i].ID_Questions)
                    {
                        t = 1;
                        coun = i;
                        break;
                    }

                }

            if (ans.size() != 0 && t==1)
            {
                ans.erase( ans.begin() + coun);
            }

            fstream Answers;
            Answers.open("Answers_data.txt", ios::out);
            for (int i = 0; i < ans.size(); i++)
		        {
				Answers << ans[i].ID_Questions << "\n";
				Answers << ans[i].answer << "\n";
		        }
            Answers.close();
            fstream que1;

            que1.open("ques_data.txt", ios::out);
            if (que.size() != 0)
             {
			    que.erase(que.begin() + k2 );

		     }
             for (int i = 0; i < que.size(); i++)
		{

				que1 << que[i].ID_Questions<< "\n";
				que1 << que[i].from << "\n";
				que1 << que[i].to<< "\n";
				que1<<  que[i].questions << "\n";

		}
		que1.close();


            }
        else
        {
            cout <<" you cannot clear the question\n";
        }

    }
    void view_Q_A()
    {
        cleear();

        for (int i = 0; i < que.size(); i++)
            {
             cout<<"Question ID : "<<que[i].ID_Questions << "\n";
             cout << "\n";
              cout << "from :  " << que[i].from <<" -->"<< " to :  " << que[i].to << "\n";
             cout << "\n";
             cout <<"Question : " <<que[i].questions<<"\n";
             cout << "\n";
            bool ck = false;
             for(int x=0;x<ans.size();x++)
             {
                if (que[i].ID_Questions==ans[x].ID_Questions)
                {

                    cout<< ans[x].answer<<"\n";
                    cout << "\n";
                    ck=true;

                }
             }
             if (ck == false)
                {
                    cout <<"There is no answer\n";
                    cout << "\n";
                }
              /*
              else if (que[i].ID_Questions=0)
              {
                cout <<"No Question";
              }
            */
            }
    }


};

int main()
{

    Data ob;
    ob.lines_data();
    Questions_Answer qa;
    int num = 1;

    while (num)
    {
        ob.first_menu();
        cin >> num;
        if (num == 1)
        {
            ob.Input();
        }
        else if (num == 2)
        {
           // ob.show_users();
            ob.sign_in();


        }
        else if (num ==3)
        {
            return 0;
        }
        int number = 1;
       while (number)
       {
           ob.list();
           cin >> number;
         if (number == 5)
         {
            ob.show_users();
         }
         else if (number == 3)
         {
             qa.users_without_curr();
             qa.id_Qu();
         }
        else if (number==4)
        {

            qa.response();

        }
        else if (number==1)
        {
            qa.ID_test();
        }
        else if (number==2)
        {
            qa.qu_from();
        }
        else if (number==6)
        {
            qa.delete_Questions();
        }
        else if (number==7)
        {
            qa.view_Q_A();
        }

       }
    }
    ob.list();
    return 0;
}