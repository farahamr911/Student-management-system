#include<stdio.h>
#include<stdlib.h>
int x=1;
struct student
{
	int id;
	char name[50];
	int age;
	float gpa;
};

struct node
{
	struct student data;
    struct node* next;
};

struct node * head=NULL;


/*..............................................*/
void checkID(int ID)
{
	struct node *temp;
	if (head==NULL)
	{
	    x=1;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data.id==ID)
		{
			printf("The ID already exist\n");
			x=0;
			return;
		}
		temp=temp->next;
	}
	x=1;
	return;
}
/*.....................return the error message and if already exist x will be 0*/


void addStudent(struct student * const ptr)
{
	struct node *temp = NULL;
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

	newnode->data = *ptr;
	newnode->next = NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	return;
}
/*......................................*/

void displayStudents(void)
{
	if (head==NULL)
	{
		printf("the list is empty\n");
		return;
	}
	struct node * temp=head;
	while(temp!=NULL)
	{
		printf("ID: %d,Name: %s ,Age: %d,GPA: %f\n",temp->data.id,temp->data.name,temp->data.age,temp->data.gpa);
		temp = temp->next;
	}
	return;
}

void searchStudentByID(int id)
{
	if (head==NULL)
		{
			printf("the list is empty\n");
			return;
		}
	struct node*temp=head;
	while(temp!=NULL)
	{
		if(temp->data.id==id)
		{
			printf("ID: %d,Name: %s ,Age: %d,GPA: %f\n",temp->data.id,temp->data.name,temp->data.age,temp->data.gpa);
			return;
		}
		temp = temp->next;
	}
	printf("the student is not found\n");
	return;
}

void updateStudent(int id)
{
	if (head==NULL)
		{
			printf("the list is empty\n");
			return;
		}
	struct node*temp=head;
	while(temp!=NULL)
	{
		if(temp->data.id==id)
		{
			printf("NewID: ");
			scanf("%d",&(temp->data.id));
			printf("NewName: ");
			scanf("%s",(temp->data.name));
			printf("NewAge: ");
			scanf("%d",&(temp->data.age));
			printf("NewGPA: ");
			scanf("%f",&(temp->data.gpa));
			printf("The student information updated successfully\n");
			return;
		}
		temp = temp->next;
	}
	printf("the student is not found\n");
	return;
}


void deleteStudent(int id)
{
	struct node *temp = NULL;
	struct node *prev = NULL;
	struct node * delete_student = NULL;
	/*check if the list is empty*/
	if (head==NULL)
		{
			printf("the list is empty\n");
			return;
		}
	/*check if the required node to be deleted is the fist (head)*/
	if(head->data.id==id)
	{
		delete_student=head;
		head=head->next;
		free(delete_student);
		printf("the student deleted successfully\n");
		return;
	}

	temp=head->next;
	prev=head;
	while(temp!=NULL)
	{
		if(temp->data.id==id)
		{
			delete_student=temp;
			free(delete_student);
			prev->next=temp->next;
			printf("the student deleted successfully\n");
			return;
		}
		temp=temp->next;
		prev=prev->next;
	}
	printf("the ID not in the list\n");
	return;
}


int SizeOfList(void)
{
	struct node *temp;
	int size=0;
	temp=head;
	while(temp!=NULL)
	{
		size=size+1;
		temp=temp->next;
	}
	return size;
}
float calculateAverageGPA(void)
{
	float sum=0,average;
	struct node *temp;
	if (head==NULL)
	{
		return 0.0;
	}
	temp=head;
	while(temp!=NULL)
	{
		sum=sum+(temp->data.gpa);
		temp=temp->next;
	}
	average=sum/(SizeOfList());
	return average;
}

void searchStudentByGPA(int gpa)
{
	struct node*temp=head;
	while(temp!=NULL)
	{
		if(temp->data.gpa==gpa)
		{
			printf("Student with Highest GPA has ID: %d,Name: %s ,Age: %d,GPA: %f\n",temp->data.id,temp->data.name,temp->data.age,temp->data.gpa);
			return;
		}
		temp = temp->next;
	}
}
void searchHighestGPA(void)
{
	if (head==NULL)
		{
			printf("the list is empty\n");
			return;
		}
	struct node *temp=head;
	int Highest_GPA=head->data.gpa;
	while(temp!=NULL)
	{
		if((temp->data.gpa)>Highest_GPA)
		{
			Highest_GPA=temp->data.gpa;
		}
		temp=temp->next;
	}
	searchStudentByGPA(Highest_GPA);
	return;
}

int main (void)
{
	int mode;
	do
	{
		setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter choice:");
		scanf("%d",&mode);

	    if (mode==1)
	    {
	    	struct student input_student;
	    	printf("ID: " );
	    	scanf("%d",&(input_student.id));
	    	checkID(input_student.id);
	    	if(x==0)
	    	{
	    		continue;
	    	}
	    	printf("Name: ");
	    	scanf("%s",(input_student.name));
	    	printf("Age: ");
	    	scanf("%d",&(input_student.age));
	    	printf("GPA: ");
	    	scanf("%f",&(input_student.gpa));
	    	struct student * ptr =&input_student;
	    	addStudent(ptr);
	         }
	    else if (mode==2)
	        {
	          displayStudents();
	        }
	    else if(mode==3)
	    {
	    	int x;
	    	printf("Enter Student ID to Search:");
	    	scanf("%d",&x);
	    	searchStudentByID(x);
	    }
	    else if (mode==4)
	    {
	    	int x;
	    	printf("Enter Student ID to update:");
	    	scanf("%d",&x);
	    	updateStudent(x);

	    }
	    else if(mode==5)
	    {
	    	int x;
	    	printf("Enter Student ID to be deleted:");
	    	scanf("%d",&x);
	    	deleteStudent(x);
	    }
	    else if(mode==6)
	    {
	    	float average=calculateAverageGPA();
	    	printf("Average GPA= %f \n",average);
	    }
	    else if(mode==7)
	    {
	    	searchHighestGPA();
	    }

	}
	while(mode!=8);
	printf("Exit");
    	return 0;
}
