#include<iostream>
#include<string>
using namespace std;
struct DateOfBirth
{
    int date,month,year;
};
class Student
{
private:
    string name;
    int rollNumber;
    int age;
    int currentYear;
    string gender;
    DateOfBirth dob;//declare structure in the class
    int howManyCourse;
    float gpa;
    float courseGrades[100];

public:
    void setter();//Input Method
    void calculateAge();//Calculate Age by this Method
    void calculateGPA();//Calculate GPA by this Method
    string catGender();//Catagorized Male or Felemale or other
    bool legalAge();//Define legal age
    string reviewName();//for applying shorting by name
    int reviewRoll();//for applying shorting by roll
    void getter();//Output method

};
void Student :: setter() //Input Method: By this we can input our value. this is default
{
    cin.ignore();//To consume the newline character left in the input buffer
    cout<<"Enter Student Name:";
    getline(cin,name);
    cout<<"Enter Roll Number:";
    cin>>rollNumber;
    cout<<"Enter the student Gender[M/F/O]:";
    cin>>gender;
    cout<<"Date of Birth[dd/mm/yyyy]: ";
    cin>>dob.date>>dob.month>>dob.year;
    cout<<"Enter current year: ";
    cin>>currentYear;
    cout<<"Student course Details"<<endl;
    cout<<"How many subject are there? "<<endl;
    cout<<"=>";cin>>howManyCourse;
    cout<<"Enter the course grades:"<<endl;
    for(int i=0; i<howManyCourse; i++)
    {
        cout<<"=>";cin>> courseGrades[i];
    }

}
int Student:: reviewRoll()//This method helps to put roll number in reviewRoll function for sorting By Roll function
{
    return rollNumber;
}
void sortByRoll(Student students[],int n)
{
    for(int i=0; i<n-1;i++)
    {
        for(int j=0; j<n-i-1;j++)
        {
            if(students[j].reviewRoll()>students[j+1].reviewRoll())
            {
                Student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
        }
    }
}


string Student::reviewName()//This method helps to put the name value in reviewName function for Sorting by Name
{
    return name;
}

//Sorting Function
void sortByName(Student students[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            Student temp= students[j];
            students[j]=students[j+1];
            students[j+1]=temp;
        }
    }
}

// Search By Roll Function
int searchByRoll(Student students[],int n, int desirRoll)
{
    for(int i=0; i<n; i++)
    {
        if (students[i].reviewRoll()==desirRoll)
            return i;
    }
        return -1;
}

//Legal Age Determine Method
bool Student:: legalAge()
{
    if(age>18)
        return true;
    else
        return false;
}

//Gender Determine
string Student :: catGender()
{
    if(gender=="M" || gender=="m" )
        return "Male";
    else if(gender=="F" || gender=="f")
        return "Female";
    else if (gender=="O"||gender=="o")
        return "Other";
    else
        return "Invalid!";
}

//Age calculation Method
void Student :: calculateAge()
    {

    age=(currentYear-dob.year);
    }

//Calculation Method
void Student :: calculateGPA()
    {
        double sum=0;
        for(int i=0; i< howManyCourse ; i++)
        {
            sum += courseGrades[i];
        }
        gpa = sum / howManyCourse;
        }
void Student::getter() //Output Method
{
    cout<<endl;
    cout<<"Student Name:"<<name<<endl;
    cout<<"Student Roll Number:"<<rollNumber<<endl;
    calculateAge();
    cout<<"Student Age:"<<age<<endl;
    cout<<"Legal Age: "<<(legalAge()?"Yes":"No")<<endl;
    cout<<"Student Gender:"<<catGender()<<endl;
    cout<<"Student Date of Birth: "<<dob.date<<"/"<<dob.month<<"/"<<dob.year<<endl;
    cout<<"Student course grades are:"<<endl;
    for(int i=0; i < howManyCourse; i++)
    {
        cout<<"Course "<<i+1<<" grades :"<< courseGrades[i]<<" "<<endl;
    }
    calculateGPA();
    cout<<"GPA is: "<<gpa<<endl;
    cout<<"-----------------------------------"<<endl;
}
int main()// Main Function
{
    int studentNo,desiredRoll;
    cout<<"How many students you want to input: "<<endl;
    cout<<"=>";cin>>studentNo;
    Student StudentsDetail[studentNo];
    for(int i=0; i<studentNo;i++)//for loop inputing value
    {
        StudentsDetail[i].setter();
    }
    cout<<"------------All INFORMATION----------------";
   for(int i=0; i < studentNo ; i++)//for loop for displaying All
    {
        StudentsDetail[i].getter();
    }
    //This is for user choice
    int choice;
    string k; //k is taken to make Desired rolled function
    cout<<"Sorting by Roll Number [Press 1]"<<endl;
    cout<<"Sorting by Name [Press 2]"<<endl;
    cout<<"=>";
    cin>>choice;
    if (choice ==1)
    {
        sortByRoll(StudentsDetail,studentNo);
    }
    else if(choice ==2)
    {
        sortByName(StudentsDetail,studentNo);
    }
    else
    {
        cout<<"Invalid!";
    }
    cout<<"------------All INFORMATION AFTER CHOICE OF USER ----------------";
   for(int i=0; i < studentNo ; i++)//for loop for displaying All
    {
        StudentsDetail[i].getter();
    }
    cout<<"To find by roll number [Press Y] or terminate [Press N] "<<endl;
    cout<<"=>";cin>>k;
    if(k=="Y" || k=="y")
    {
        cout<<"Enter your desired Roll Number: ";cin>>desiredRoll;
        int result=searchByRoll(StudentsDetail,studentNo,desiredRoll);
        if (result!=-1)
            {
           cout<<endl<<"Student found at index "<< result<< ":"<<endl;
           StudentsDetail[result].getter();
            }
        else
        {
            cout<<"Student with "<<desiredRoll<<" roll is not exists.";
        }
    }
    else if (k=="N"||k=="n")
    {
        cout<<"Thank you!";
        return 0;
    }
    else
    {
        cout<<"Invalid!";
    }



    return 0;
}

