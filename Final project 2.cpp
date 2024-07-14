#include<stdio.h>
#include<string.h>
#define SIZE 120
#define SIZE2 70
//functions protoype
int entercustomer(char c[][SIZE2], int counter);
void displaycustomers(char c[][SIZE2], int counter);
void quitscreen();
void display();
int entervechile(char v[][SIZE2], int counter);
void displayvechiles(char v[][SIZE2], int counter);
//function main
int main() {

	char c[SIZE][SIZE2], v[SIZE][SIZE2];
	int ccount = 0, vcount = 0;
	char enterbutton;
	int choice;
	int  end = 1;
	//while loop nested with a switch
	while (end == 1)
	{
		//v means vehicle but for efficiency we used v
		//c means customer but for efficiency we used c
		display();
		printf("Enter a number :");
		scanf_s("%d", &choice);
		//switch with 6 cases
		switch (choice)
		{
		case 1:

			scanf_s("%c", &enterbutton);
			ccount = entercustomer(c, ccount);
			break;

		case 2:

			scanf_s("%c", &enterbutton);
			vcount = entervechile(v, vcount);
			break;
		case 3:

			puts("Customer Infomration : ");
			displaycustomers(c, ccount);
			break;

		case 4:

			puts("Vechiles Infomration : ");
			displayvechiles(v, vcount);
			break;

		case 5:

			puts("hope you enjoy our application and find it helpfull :)");
			end = 2;
			break;

		default:

			quitscreen();
		}
	}

	return 0;
}
void displaycustomers(char c[][SIZE2], int counter) {
	printf("%s%19s%21s%20s\n", "Number.", "Customer ID", "Customer Name", "Customer Phone");

	for (int i = 0; i < counter; i += 3)
	{
		printf("%-16d%-19s%-20s%s\n", (i * 1 / 3) + 1, c[i], c[i + 1], c[i + 2]);
	}
}

int entervechile(char v[][SIZE2], int counter) {
	puts("Please enter car's Model year: ");
	scanf_s("%s", v[counter++], SIZE2);
	puts("Please enter car's Make: ");
	scanf_s("%s", v[counter++], SIZE2);
	puts("Please enter car's Model name: ");
	scanf_s("%s", v[counter++], SIZE2);
	puts("Please enter car's Model License plate number: ");
	scanf_s("%s", v[counter++], SIZE2);
	puts("Please enter Customer number who is currently renting vehicle: ");
	scanf_s("%s", v[counter++], SIZE2);
	return counter;
}
void displayvechiles(char v[][SIZE2], int counter) {
	printf("%s%17s%19s%20s%29s%24s\n", "Number.", "Model year", "Make", "Model name", "License plate number", "Customer number");
	for (int i = 0; i < counter; i += 5) {
		printf("%-15d%-23s%-16s%-22s%-27s%s\n", (i * 1 / 5) + 1, v[i], v[i + 1], v[i + 2], v[i + 3], v[i + 4]);
	}
}
void quitscreen() {
	puts("incorect option Try Again :) ");
	puts("");
}
void display() {
	puts("Welcome to the Car Rental Application");
	puts("1 - to add a new customer");
	puts("2 - to add a new vehicle");
	puts("3 - to print all customers information");
	puts("4 - to print all vehicles information");
	puts("5 - to quit");
}
int entercustomer(char c[][SIZE2], int counter) {
	char x;
	printf("Please enter your ID: \n");
	scanf_s("%s", c[counter++], SIZE2);
	scanf_s("%c", &x);
	printf("Please enter your Name: \n");
	fgets(c[counter++], SIZE2, stdin);
	size_t length = strlen(c[counter - 1]) - 1;

	if (c[counter - 1][length] == '\n')
	{
		(c[counter - 1][length] = '\0');
	}
	printf("Please enter your Phone number: \n");
	scanf_s("%s", c[counter++], SIZE2);

	return counter;
}

