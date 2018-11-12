#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void mainList();
void teacherRegistration();
void studentRegistration();
void studentLogin();
void teacherLogin();
void teacher_menu_click(int clicked,char *name, char *course);
void student_menu_click(int clicked,char *name,char *ID);
void grading_policy(char *name,char *ID);
void teacherDashBoard(char *name, char *course);
void studentDashBoard(char *name, char *ID);
void enroll(char *course_name, char *id,char *name);
void courseList(char *name,char *ID);
void studentCourseList(char *name,char *ID);
int studentCoursleListLines(char *generated_course_path);
int lineNumber();
void studentList(char *name, char *course);
void studentInformation(char *id);
void setMarks(char *name, char *course);
void checkMarkDistribution(char *name,char *ID);
void markStudent(char *name, char *course);
const char * grade(float num);
void submitGrade(char *studnetID, char *course, char *name, int marks);
int main(){
	  printf("-----------------------------------------------------------------------------\n");
    printf("WELCOME TO TEACHER STUDENT MANAGEMENT SYSTEM\n");
    printf("-----------------------------------------------------------------------------\n");
    mainList();
   
}

void mainList(){
	  int input;
	  printf("1.Registration(TEACHER)\n");
    printf("2.Login(TEACHER)\n");
    printf("3.Registration(STUDENT)\n");
    printf("4.Login(STUDENT)\n->");
    scanf("%d", &input);
    if(input==1){
    	teacherRegistration();
    }
    else if(input==2){
    	teacherLogin();
    }else if(input == 3){
		studentRegistration();
    }else if(input == 4){
    	studentLogin();
    }else{
    	printf("Invalid Input\n");
    	mainList();
    }
}

void studentDashBoard(char *name, char *ID){
	char word[] = ".txt";
	if(strstr(ID, word) != NULL) {
    	strtok(ID,".");
	}
	printf("-----------------------------------------------------------------------------\n");
	printf("STUDENT DASHBOARD\t");
	printf("|%s\t\t\t|ID:%s\n",name,ID);
	printf("-----------------------------------------------------------------------------\n");
	int Input_number;
    printf("1. Your Courses\n");
    printf("2. Enroll To a Course\n");
    printf("3. Grading Policy\n");
    printf("4. Check Mark Distribution\n");
    printf("5. Exit\n->");
    scanf("%d", &Input_number);
    student_menu_click(Input_number,name,ID);
    
}
void teacherDashBoard(char *name, char *course){
	strtok(course,"\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("TEACHER DASHBOARD\t");
	printf("Name:%s\tCourse:%s\n",name,course);
	printf("-----------------------------------------------------------------------------\n");
	int Input_number;
    printf("1. Student Profile\n");
    printf("2. Set Mark Distribution\n");
    printf("3. Student Marking\n");
    printf("4. Exit\n->");
    scanf("%d", &Input_number);
    teacher_menu_click(Input_number,name,course);
}



void student_menu_click(int clicked,char *name,char *ID)
{
switch(clicked){
    case 1:
    	studentCourseList(name,ID);
        break;
    case 2:
    	courseList(name,ID);
        break;
    case 3:
    	grading_policy(name,ID);
        break;
    case 4:
    	checkMarkDistribution(name,ID);
        break;
    case 5:
    	exit(1);
        break;
    default:
        printf("You have entered a wrong key.\nPlease try again with the correct key");
}
}


void grading_policy(char *name,char *ID){
    printf("-------------------------------------------\n");
    printf("|              GRADING POLICY             |\n");
    printf("|-----------------------------------------|\n");
    printf("|NUMERICAL SCORE|LETTER GRADE|GRADE POINTS|\n");
    printf("|-----------------------------------------|\n");
    printf("|94 and above   |A EXCELLENT |     4.0    |\n");
    printf("|90 - 93        |A-          |     3.7    |\n");
    printf("|87 - 89        |B+          |     3.3    |\n");
    printf("|83 - 86        |B GOOD      |     3.0    |\n");
    printf("|80 - 82        |B-          |     2.7    |\n");
    printf("|77 - 79        |C+          |     2.3    |\n");
    printf("|73 - 76        |C AVERAGE   |     2.0    |\n");
    printf("|70 - 72        |C-          |     1.7    |\n");
    printf("|67 - 69        |D+          |     1.3    |\n");
    printf("|60 - 66        |D POOR      |     1.0    |\n");
    printf("| Below         |F FAILURE   |     0.0    |\n");
    printf("------------------------------------------\n");
    studentDashBoard(name,ID);
}



void teacher_menu_click(int clicked,char *name,char *course)
{
switch(clicked){
    case 1:
    	studentList(name,course);
        break;
    case 2:
    	setMarks(name,course);
        break;
    case 3:
    	markStudent(name,course);
        break;
    case 4:
    	exit(1);
        break;
    default:
        printf("You have entered a wrong key.\nPlease try again with the correct key");
}
}



void teacherLogin(){
	struct teacher
	{
   		char email[256];
		char password[256];
	} t;
printf("-----------------------------------------------------------------------------\n");
	printf("TEACHER LOGIN\n");
	printf("-----------------------------------------------------------------------------\n");
	bool logged_in = false;
	char file_read[256];
	char path[256] = "Teachers/";
	int lines =0;
	printf("Enter your email\n->");
	scanf("%s",t.email);
	printf("Enter your password\n->");
	scanf("%s",t.password);
	char *generated_path = strcat(path,strcat(t.email,".txt"));
	FILE *f = fopen(generated_path, "r");
	if (f != NULL)
	{
   	 while(fgets( file_read, sizeof( file_read ), f ) != NULL){
   	 	if(lines == 0){
   	 		if(strcmp(strcat(t.password,"\n"),file_read) == 0){
   	 			
   	 			logged_in = true;
   	 		}else{
   	 			printf("You've entered wrong password please try again correctly\n");
   	 			teacherLogin();
   	 			break;
   	 		}
   	 	}else if(lines==1 && logged_in){
   	 		int i = 0;
    		char *p = strtok (file_read, "\t");
    		char *array[2];
   	 		while (p != NULL)
    		{
        		array[i++] = p;
        		p = strtok (NULL, "\t");
    		}
    		
    		i =0;
   	 		char *r = strtok (array[0], ":");
   	 		char *first_array[2];
   	 		while (r != NULL)
    		{
        		first_array[i++] = r;
        		r = strtok (NULL, ":");
    		}
   	 		

   	 		i =0;
   	 		char *q = strtok (array[1], ":");
   	 		char *second_array[2];
   	 		while (q != NULL)
    		{
        		second_array[i++] = q;
        		q = strtok (NULL, ":");
    		}
   	 		
   	 		teacherDashBoard(first_array[1],second_array[1]);
   	 	}	
		lines++;
   	 }
    	
	}else{
		printf("Wrong email. Please try again\n");
		teacherLogin();
	}
	fclose(f);
}


void studentLogin(){
	struct student
	{
   	char id[256];
		char password[256];
	} s;
printf("-----------------------------------------------------------------------------\n");
	printf("STUDENT LOGIN\n");
	printf("-----------------------------------------------------------------------------\n");
	bool logged_in = false;
	char file_read[256];
	char path[256] = "Students/";
	int lines =0;
	printf("Enter your id\n->");
	scanf("%s",s.id);
	printf("Enter your password\n->");
	scanf("%s",s.password);
	char *generated_path = strcat(path,strcat(s.id,".txt"));
	FILE *f = fopen(generated_path, "r");
	if (f != NULL)
	{
   	 while(fgets( file_read, sizeof( file_read ), f ) != NULL){
   	 	if(lines == 0){
   	 		if(strcmp(strcat(s.password,"\n"),file_read) == 0){
   	 			
   	 			logged_in = true;
   	 		}else{
   	 			printf("You've entered wrong password please try again correctly\n");
   	 			studentLogin();
   	 			break;
   	 		}
   	 	}else if(lines==1 && logged_in){
   	 		studentDashBoard(file_read,s.id);
   	 	}	
		lines++;
   	 }
    	
	}else{
		printf("Wrong ID. Please try again\n");
		studentLogin();
	}
	fclose(f);
}






void teacherRegistration(){
	printf("-----------------------------------------------------------------------------\n");
	printf("TEACHER REGISTRATION PROCESS\n");
	printf("-----------------------------------------------------------------------------\n");
	char name[256];
	char email[256];
	char password[256];
	char course[256];
	char path[256] = "Teachers/";
	char course_path[256] = "Courses/";
	printf("Enter your name\n->");
	scanf("%s",name);
	printf("Enter your email\n->");
	scanf("%s",email);
	printf("Enter your password\n->");
	scanf("%s",password);
	printf("Enter your course code\n->");
	scanf("%s",course);
	char *generated_path = strcat(path,strcat(email,".txt"));
	FILE *f = fopen(generated_path, "r");
	FILE *fc = fopen("course_list.txt", "a");
	if (f != NULL)
	{
   	 	printf("Email already taken. Please try with another email!\n");
   	 	email[0] = '\0';
   	 	teacherRegistration();
   	 	fclose(f);
    	
	}else{
		FILE *fw = fopen(generated_path, "w");
		if (fw == NULL)
		{
   	 		printf("something went wrong\n");
    		
		}else{
			fprintf(fw, "%s\n", password);
			fprintf(fw, "Name:%s\tCourse:%s\n",name, course);
			fprintf(fc, "%s%s\n",course, name);
			fclose(fw);
			fclose(fc);
			printf("------------------------------------------------------------------------------------------\n");
			printf("Thank you for registering with our system you can now login from the dashboard\n");
			printf("------------------------------------------------------------------------------------------\n");
			mainList();
		}
	}
	fclose(f);
	
}


void studentRegistration(){
	printf("-----------------------------------------------------------------------------\n");
	printf("STUDENT REGISTRATION PROCESS\n");
	printf("-----------------------------------------------------------------------------\n");
	char name[256];
	char id[256];
	char password[256];
	char dept[256];
	char path[256] = "Students/";
	char course_path[256] = "Courses/";
	printf("Enter your name\n->");
	scanf("%s",name);
	printf("Enter your id\n->");
	scanf("%s",id);
	printf("Enter your password\n->");
	scanf("%s",password);
	printf("Enter your department name\n->");
	scanf("%s",dept);
	char *generated_path = strcat(path,strcat(id,".txt"));
	FILE *f = fopen(generated_path, "r");
	if (f != NULL)
	{
   	 	printf("You already have an account for login to the dashboard\n");
   	 	studentRegistration();
   	 	fclose(f);
    	
	}else{
		FILE *fw = fopen(generated_path, "w");
		if (fw == NULL)
		{
   	 		printf("something went wrong\n");
    		
		}else{
			fprintf(fw, "%s\n", password);
			fprintf(fw, "Name:%s\t Departmnet:%s\n",name, dept);
			fclose(fw);
			printf("------------------------------------------------------------------------------------------\n");
			printf("Thank you for registering with our system you can now login from the dashboard\n");
			printf("------------------------------------------------------------------------------------------\n");
			mainList();
		}
	}
	fclose(f);
	
}

void enroll(char *course_name, char *id,char *name){
	char student_course_path[256] = "Courses/";
	char teacher_course_path[256] = "Courses/";
	char *generated_student_course_path = strcat(student_course_path,strcat(id,".txt"));
	char *generated_teacher_course_path = strcat(teacher_course_path,strcat(course_name,".txt"));
	FILE *fscw = fopen(generated_student_course_path, "a");
	FILE *ftcw = fopen(generated_teacher_course_path, "a");
	strtok(course_name,".");
	strtok(id,".");
	fprintf(fscw, "%s\t Grade: Not Submitted\n", course_name);
	fprintf(ftcw, "%s\t Grade: Not Submitted\n", id);
	fclose(fscw);
	fclose(ftcw);
	printf("Enrolled Successfully\n");
	studentDashBoard(name,id);
}

int lineNumber(){
 #define MAX_SIZE 1000
    char line[MAX_SIZE];
    FILE *in_file;
    in_file = fopen("course_list.txt", "r");
    if(in_file == NULL){
        printf("problem\n");
    }

    int counter = 0; /*Number of lines*/

    while(fgets(line, sizeof(line), in_file) != NULL){
        counter++;
    }
    return counter;
}

int studentCoursleListLines(char *generated_course_path){
 #define MAX_SIZE 1000
    char line[MAX_SIZE];
	FILE *in_file;
    in_file = fopen(generated_course_path, "r");
    if(in_file == NULL){
        printf("problem\n");
    }

    int counter = 0; /*Number of lines*/

    while(fgets(line, sizeof(line), in_file) != NULL){
        counter++;
    }
    return counter;
}

void courseList(char *name,char *ID){
	int MAXLINES =500;
	 int i = 0;
	 int input_index;
    char lines[MAXLINES][BUFSIZ];
    FILE *fp = fopen("course_list.txt", "r");
    if(fp==NULL){
      printf("There is no course available to enroll in\n");
      studentDashBoard(name,ID);
    }else{
      while (i < MAXLINES && fgets(lines[i], sizeof(lines[0]), fp))
    {
        lines[i][strlen(lines[i])-1] = '\0';
        i++;
    }
    
    fclose(fp);
    printf("------------------------------------------------------------------------------------------\n");
    printf("ALL COURSE LIST\n");
    printf("------------------------------------------------------------------------------------------\n");
    int index = lineNumber();
    for(int j =0 ; j<index;j++ ){
      printf("%d. %s\n", j+1,lines[j]); 
    }
    printf("#Choose what course you want to enroll in\n->");
    scanf("%d",&input_index);
    if(input_index>index){
      printf("Invalid Input Please Try Again\n");
      courseList(name,ID);
    }else{
       enroll(lines[input_index-1],ID,name);
    }
   
    }
    
    
}	

void studentCourseList(char *name,char *ID){
	int MAXLINES =500;
	 int i = 0;
	 char student_course_path[256] = "Courses/";
	 char *generated_student_course_path = strcat(student_course_path,strcat(ID,".txt"));
    char lines[MAXLINES][BUFSIZ];
    FILE *fp = fopen(generated_student_course_path, "r");
    if(fp==NULL){
      printf("Currently You're not enrolled in any course\n");
      studentDashBoard(name,ID);
    }else{
      while (i < MAXLINES && fgets(lines[i], sizeof(lines[0]), fp))
    {
        lines[i][strlen(lines[i])-1] = '\0';
        i++;
    }
    
      fclose(fp);
      printf("------------------------------------------------------------------------------------------\n");
      printf("YOUR COURSE LIST\n");
      printf("------------------------------------------------------------------------------------------\n");
       int index = studentCoursleListLines(generated_student_course_path);
      for(int j =0 ; j<index;j++ ){
        printf("%d. %s\n", j+1,lines[j]); 
       }
       studentDashBoard(name,ID);
      }
    
}

void checkMarkDistribution(char *name,char *ID){
	int MAXLINES =500;
	int i = 0;
	int input_index;
	char st_ID[256];
	char st_name[256];
	strcpy(st_name,name);
	strcpy(st_ID,ID);
	char marks_path[256] = "Marks/";
	char student_course_path[256] = "Courses/";
	char *generated_student_course_path = strcat(student_course_path,strcat(ID,".txt"));
    char lines[MAXLINES][BUFSIZ];
    FILE *fp = fopen(generated_student_course_path, "r");
    if(fp==NULL){
       printf("Currently You're not enrolled in any course\n");
       studentDashBoard(name,ID);
    }else{
      while (i < MAXLINES && fgets(lines[i], sizeof(lines[0]), fp))
    {
        lines[i][strlen(lines[i])-1] = '\0';
        i++;
    }
    
    fclose(fp);
    printf("------------------------------------------------------------------------------------------\n");
    printf("YOUR COURSE LIST\n");
    printf("------------------------------------------------------------------------------------------\n");
    int index = studentCoursleListLines(generated_student_course_path);
    for(int j =0 ; j<index;j++ ){
      printf("%d. %s\n", j+1,lines[j]); 
    }
    printf("#Choose what course's mark distribution you want to check\n->");
    scanf("%d",&input_index);
    if(input_index>index){
      printf("Invalid Input Please Try Again\n");
      checkMarkDistribution(st_name,st_ID);
    }else{
      char st_course [256]; 
      strcpy(st_course,strtok(lines[input_index-1],"\t"));
      FILE *myFile;
      myFile = fopen(strcat(marks_path,strcat(strtok(lines[input_index-1],"\t"),".txt")), "r");
      int numberArray[4];
      int i;
      for (i = 0; i < 16; i++)
      {
          fscanf(myFile, "%d", &numberArray[i]);
      }
      printf("------------------------------------------------------------------------------------------\n");
      printf("MARK DISTRIBUTION FOR %s\n",st_course);
      printf("------------------------------------------------------------------------------------------\n");
      printf("Home Work = %d %%\n", numberArray[0]);
      printf("Quiz = %d %%\n", numberArray[1]);
      printf("Midterm = %d %%\n", numberArray[2]);
      printf("Final = %d %%\n", numberArray[3]);
      studentDashBoard(st_name,st_ID);
    }
    
    }
    
}	



void studentList(char *name, char *course){
	int MAXLINES =500;
	int i = 0;
	int input_index;
	char st_course[256];
	char st_name[256];
	strcpy(st_course,course);
	strcpy(st_name,name);
	char *course_name = strcat(course,name);
	char student_course_path[256] = "Courses/";
	char *generated_teacher_course_path = strcat(student_course_path,strcat(course_name,".txt"));
    char lines[MAXLINES][BUFSIZ];
    FILE *fp = fopen(generated_teacher_course_path, "r");
    if(fp == NULL){
      printf("No Student Found\n");
      teacherDashBoard(name,course);
    }else{
      while (i < MAXLINES && fgets(lines[i], sizeof(lines[0]), fp))
    {
        lines[i][strlen(lines[i])-1] = '\0';
        i++;
    }
    
    fclose(fp);
    printf("------------------------------------------------------------------------------------------\n");
    printf("YOUR STUDENTS LIST\n");
    printf("------------------------------------------------------------------------------------------\n");
    int index = studentCoursleListLines(generated_teacher_course_path);
    for(int j =0 ; j<index;j++ ){
      printf("%d. %s\n", j+1,strtok(lines[j],"\t")); 
    }
    printf("#Choose your student to see their informations\n->");
    scanf("%d",&input_index);
    if(input_index>index){
      printf("Invalid Input Please Try Again\n");
      studentList(st_name,st_course);
    }else{
      studentInformation(strtok(lines[input_index-1],"\t"));
      teacherDashBoard(st_name,st_course);
    }
   
    }
    
}

void studentInformation(char *id){

	printf("-----------------------------------------------------------------------------\n");
	printf("STUDENT INFORMATION\n");
	printf("-----------------------------------------------------------------------------\n");
	char file_read[256];
	char path[256] = "Students/";
	int lines =0;
	char *generated_path = strcat(path,strcat(id,".txt"));
	FILE *f = fopen(generated_path, "r");
	if (f != NULL)
	{
   	 while(fgets( file_read, sizeof( file_read ), f ) != NULL){
   	 	if(lines==1){
   	 		printf("%s\n",file_read );
   	 	}	
		lines++;
   	 }
    	
	}else{
		printf("Wrong ID. Please try again\n");
		studentLogin();
	}
	fclose(f);
}

void setMarks(char *name, char *course){
	char marks_path[256] = "Marks/";
	char st_course[256];
	char st_name[256];
	int hw;
	int quiz;
	int mid;
	int final;
	strcpy(st_course,course);
	strcpy(st_name,name);
	char *course_name = strcat(course,name);
	char *generated_teacher_marks_path = strcat(marks_path,strcat(course_name,".txt"));
	FILE *fmw = fopen(generated_teacher_marks_path, "w");
	printf("Enter home work percantage\n->");
	scanf("%d",&hw);
	printf("Enter quiz percantage\n->");
	scanf("%d",&quiz);
	printf("Enter mid percantage\n->");
	scanf("%d",&mid);
	printf("Enter final percantage\n->");
	scanf("%d",&final);
	fprintf(fmw, "%d\n", hw);
	fprintf(fmw, "%d\n", quiz);
	fprintf(fmw, "%d\n", mid);
	fprintf(fmw, "%d\n", final);
	fclose(fmw);
	printf("You've Successfully Set The Mark Distribution\n");
	teacherDashBoard(st_name,st_course);
}

void markStudent(char *name, char *course){
	int MAXLINES =500;
	int i = 0;
	int input_index;
	char st_course[256];
	char st_name[256];
	strcpy(st_course,course);
	strcpy(st_name,name);
	char *course_name = strcat(course,name);
	char student_course_path[256] = "Courses/";
	char marks_path[256] = "Marks/";
	char *generated_teacher_course_path = strcat(student_course_path,strcat(course_name,".txt"));
    char lines[MAXLINES][BUFSIZ];
    FILE *fp = fopen(generated_teacher_course_path, "r");
    if(fp == NULL){
      printf("You currently don't have any student to set marks\n");
      teacherDashBoard(st_name,st_course);
    }else{
      while (i < MAXLINES && fgets(lines[i], sizeof(lines[0]), fp))
    {
        lines[i][strlen(lines[i])-1] = '\0';
        i++;
    }
    
    fclose(fp);
    printf("------------------------------------------------------------------------------------------\n");
    printf("YOUR STUDENTS LIST\n");
    printf("------------------------------------------------------------------------------------------\n");
    int index = studentCoursleListLines(generated_teacher_course_path);
    for(int j =0 ; j<index;j++ ){
      printf("%d. %s\n", j+1,strtok(lines[j],"\t")); 
    }
    printf("#Choose your student to set their marks\n->");
    scanf("%d",&input_index);
    if(input_index>index){
      printf("Invalid Input Please Try Again\n");
      markStudent(st_name,st_course);
    }else{
      char student_id[256];
      int hw_count;
      int quiz_count;
      int mid_count;
      int final_count;
      float quiz_avg=0;
      float hw_avg=0;
      float mid_avg=0;
      float final_avg=0;
      int input_submit;
      strcpy(student_id,strtok(lines[input_index-1],"\t"));
      FILE *myFile;
      myFile = fopen(strcat(marks_path,course_name), "r");
      int numberArray[4];
      int i;
      for (i = 0; i < 16; i++)
      {
          fscanf(myFile, "%d", &numberArray[i]);
      }
      printf("------------------------------------------------------------------------------------------\n");
      printf("Marking of ID: %s\n",student_id);
      printf("------------------------------------------------------------------------------------------\n");
      printf("Home Work = %d %%\n", numberArray[0]);
      printf("Quiz = %d %%\n", numberArray[1]);
      printf("Midterm = %d %%\n", numberArray[2]);
      printf("Final = %d %%\n", numberArray[3]);

      printf("Enter how many homeworks you took ?\n->");
      scanf("%d",&hw_count);
      float hws[hw_count];
      for(int j=0;j<hw_count;j++){
        printf("Enter homework no.%d's mark out of %d\n->",j+1,numberArray[0] );
        scanf("%f",&hws[j]);
      }
      for(int j=0;j<hw_count;j++){
        hw_avg = hw_avg + hws[j];
      }
      hw_avg = hw_avg / hw_count;
      printf("Homework total percantage %0.2f\n",hw_avg );



      printf("Enter how many quizes you took ?\n->");
      scanf("%d",&quiz_count);
      float quizs[quiz_count];
      for(int j=0;j<quiz_count;j++){
        printf("Enter quiz no.%d's mark out of %d\n->",j+1,numberArray[1] );
        scanf("%f",&quizs[j]);
      }
      for(int j=0;j<quiz_count;j++){
        quiz_avg = quiz_avg + quizs[j];
      }
      quiz_avg = quiz_avg / quiz_count;
      printf("Quiz total percantage %0.2f\n",quiz_avg );


      printf("Enter how many midterms you took ?\n->");
      scanf("%d",&mid_count);
      float mids[mid_count];
      for(int j=0;j<mid_count;j++){
        printf("Enter midterm no.%d's mark out of %d\n->",j+1,numberArray[2] );
        scanf("%f",&mids[j]);
      }
      for(int j=0;j<mid_count;j++){
        mid_avg = mid_avg + mids[j];
      }
      mid_avg = mid_avg / mid_count;
      printf("Midterm total percantage %0.2f\n",mid_avg );


      printf("Enter how many finals you took ?\n->");
      scanf("%d",&final_count);
      float final[final_count];
      for(int j=0;j<final_count;j++){
        printf("Enter final no.%d's mark out of %d\n->",j+1,numberArray[3] );
        scanf("%f",&final[j]);
      }
      for(int j=0;j<final_count;j++){
        final_avg = final_avg + final[j];
      }
      final_avg = final_avg / final_count;
      printf("Midterm total percantage %0.2f\n",mid_avg );
      float total_marks = hw_avg+quiz_avg+mid_avg+final_avg;
      printf("Total number is %0.2f and the final grade is %s\n",total_marks,grade(total_marks));
      printf("Do you want to submit this grade for ID: %s ?\n1.Yes\t2.No\n", student_id);
      scanf("%d",&input_submit);
      if(input_submit==1){
        submitGrade(student_id,st_course,st_name,total_marks);
      }else if(input_submit == 2){
        teacherDashBoard(st_name,st_course);
      }else{
        printf("Invalid input\n");
        markStudent(st_name,st_course);
      }
    } 
    
    }
}

void submitGrade(char *studnetID, char *course, char *name, int marks){
     #define BUFFER_SIZE 1000
    // /* File pointer to hold reference of input file */
     FILE * fPtr;
     FILE * fTemp;
     char course_path[256] = "Courses/";
     char st_studentID[256];
     char st_course[256];
     char st_name[256];
     char dash_course[256];
     char dash_name[256];
     strcpy(st_studentID,studnetID);
     strcpy(st_course,course);
     strcpy(st_name,name);
     strcpy(dash_course,course);
     strcpy(dash_name,name);
     char buffer[BUFFER_SIZE];
     char *newline;
     char *student_course_path = strcat(strcat(course_path,studnetID),".txt");
     int line, count;
     char file_read[256];
     int lines =0;
   
    FILE *f = fopen(student_course_path, "r");
    if (f != NULL)
    {
     while(fgets( file_read, sizeof( file_read ), f ) != NULL){
       
        if(strcmp(strcat(course,name),strtok(file_read,"\t")) == 0){
         break; 
        }
        lines++;
     }
      
    }else{
        printf("Wrong ID. Please try again\n");
        teacherDashBoard(st_name,st_course);
    }

    /* Remove extra new line character from stdin */
    fflush(stdin);

    newline = strcat(strcat(strcat(st_course,st_name),"\tGrade: "),grade(marks));


    /*  Open all required files */
    fPtr  = fopen(student_course_path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == lines)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(student_course_path);

    /* Rename temporary file as original file */
    rename("replace.tmp", student_course_path);
    //printf("\nSuccessfully replaced '%d' line with '%s'.", lines, newline);
    printf("Successfully grade submitted\n");
    teacherDashBoard(dash_name,dash_course);
}

const char * grade(float x){
    
    if(x>=94 && x<=100)
    {
      return "A";
    }else if(x>=90 && x<=93)
    {
       return "A-";
    }else if(x>=87 && x<=89)
    {
        return "B+";
    }else if(x>=83 && x<=86)
    {
        return "B";
    }else if(x>=80 && x<=82)
    {
       return "B-";
    }else if(x>=77 && x<=79)
    {
        return "C+";
    }else if(x>=73 && x<=76)
    {
       return "C";
    }else if(x>=70 && x<=72)
    {
        return "C-";
    }else if(x>=67 && x<=69)
    {
        return "D+";
    }else if(x>=60 && x<=66)
    {
        return "D";
    }else if(x>=0 && x<=59)
    {
        return "F";
    }else {
        return "ERROR";
    }

}
