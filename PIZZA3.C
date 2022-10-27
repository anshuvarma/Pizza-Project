#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// node declaration
struct node
{
	int key;
	int type;
	struct node *next;
};

int total = 0, of;
struct node *head = NULL;
struct node *temp;
int base(int);
int sauce(int);
int toppings(int);
int cheese(int);
int printlist();
int receipt();
int displayoffer();

int main()
{
	int w, ch, b, s, t, c;
	printf("*******************************WELCOME TO PIZZA WORLD**************************");
	printf("\n\nEnter your choice:\n\n1)Design your own pizza\n2)offers\n3)Exit\n");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		// printf("enter size: small=200\t medium=350\t large=500\n");
		printf("\nBASE:\n1) Thin Crust..........50\n2) Pan Crust..........30\n3) Hand Toasted..........60\n4) Cheese Burst...........100\n");
		scanf("%d", &b);
		base(b);
		printf("\nSAUCE:\n1) Tomato 20\n2) Barbeque 50\n3) Salsa.........60.\n4)Jain..........200\n");
		scanf("%d", &s);
		sauce(s);
		printf("\nCHEESE:\n1) Normal Cheese...... 15\n2) Mozzarella...... 35\n3) Parmesan....... 20\n");
		scanf("%d", &c);
		cheese(c);
		printf("\nTOPPINGS:\n1) Tomato + Capsicum + Onion.......80\n2) Sweetcorn + Mushroom.....100\n3) Chicken.....110\n");
		scanf("%d", &t);
		toppings(t);
		printf("***********************cart************************\n");
		printlist();
		printf("\n\nDo you wish to make changes in your cart? (0/1)\n ");
		scanf("%d", &w);
		printf("\n%d", w);
		if (w == 0)
			receipt();
		break;
	case 2:
		printf(" CHOOSE OFFERS\n 1) 2 Pizza-20% OFF.......350\n2) Chef's Special.....300\n3) Combo......350 \n4) 1 Veg and NonVeg Pizza-10% OFF....280\n");
		scanf("%d", &of);
		displayoffer();
		break;
	case 3:
		exit(0);
		break;
	default:
		printf("Invalid");
	}
	getch();
	return 0;
	
}

int base(int data) // base fn
{
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->key = 1;
	link->type = data;
	link->next = NULL;
	head = link;
	
	return 0;

}
int sauce(int data) // sauce fn
{
	int res;
	struct node *link = (struct node *)malloc(sizeof(struct node));
	temp = head;
	link->key = 2;
	res = data + 4;
	link->type = res;
	link->next = NULL;
	if (head != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = link;
	}

	return 0;
}
int cheese(int data) // cheese fn
{
	int res;
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->key = 3;
	temp = head;
	res = data + 8;
	link->type = res;
	link->next = NULL;
	if (head != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = link;
	}

	return 0;
}
int toppings(int data) // toppings fn
{
	int res;
	struct node *link = (struct node *)malloc(sizeof(struct node));
	temp = head;
	link->key = 4;
	res = data + 11;
	link->type = res;
	link->next = NULL;
	if (head != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = link;
	}

	return 0;
}
int printlist()
{
	struct node *temp = head;
	while (temp != NULL)
	{
		if (temp->type == 1)
		{
			printf("\nBase    : thin crust......50");
			total += 50;
		}
		if (temp->type == 2)
		{
			printf("\nBase    : pancrust........30");
			total += 30;
		}
		if (temp->type == 3)
		{
			printf("\nBase    : handtoast........60");
			total += 60;
		}
		if (temp->type == 4)
		{
			printf("\nBase    : cheese burst......20");
			total += 20;
		}
		if (temp->type == 5)
		{
			printf("\nsauce   : tomato............50");
			total += 50;
		}
		if (temp->type == 6)
		{
			printf("\nsauce   :barbeque...........60");
			total += 60;
		}
		if (temp->type == 7)
		{
			printf("\nsauce   : salsa.............200");
			total += 200;
		}
		if (temp->type == 8)
		{
			printf("\nsauce   : jain...............15");
			total += 15;
		}
		if (temp->type == 9)
		{
			printf("\ncheese  : normal cheese.......35");
			total += 35;
		}
		if (temp->type == 10)
		{
			printf("\ncheese  : mozzarella............20");
			total += 20;
		}
		if (temp->type == 11)
		{
			printf("\ncheese  : parmesan.............20");
			total += 20;
		}
		if (temp->type == 12)
		{
			printf("\ntoppings: Tomato+capsicum+onion.80");

			total += 80;
		}
		if (temp->type == 13)
		{
			printf("\ntoppings: sweetcorn+mushroom.....100");
			total += 100;
		}
		if (temp->type == 14)
		{
			printf("\ntoppings: chicken................110");
			total += 110;
		}
		temp = temp->next;
	}
	return 0;
}

int receipt()
{
	printf("**********************RECEIPT***************************");
	printlist();
	printf("\nTotal.................%d", total);
	printf("\nGST...................30");
	printf("\nTOTAL.................%d", (30 + total));

	return 0;
}
int displayoffer()
{
	printf("**********************RECEIPT***************************");
	if (of == 1)
	{
		printf("\n2 Pizza-20% OFF.......350");
		total += 350;
	}
	if (of == 2)
	{
		printf("\n Chef's Special.....300");
		total += 300;
	}
	if (of == 3)
	{
		printf("\nCombo......350");
		total += 350;
	}
	if (of == 4)
	{
		printf("\n1 Veg and NonVeg Pizza-10% OFF....280");
		total += 280;
	}
	printf("\nTOTAL...........%d", total);
	return 0;
}
