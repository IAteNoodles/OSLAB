#include<stdio.h>
#include<math.h>
struct node
{
	int cf;
	int px;
	int py;
	int pz;
	struct node *link;
};
typedef struct node* NODE;
 
// Function to display the polynomial
void display(NODE head)
{
	NODE cur;
	if(head->link == head)
	{
		printf("Polynomial does not exist\n");
		return;
	}
	cur = head->link;
	while(cur != head)
	{
		if(cur->cf > 0)
		printf("+");
printf("%d ",cur->cf);
printf("x^ %d", cur->px);
printf("y^ %d", cur->py);
printf("z^ %d", cur->pz);
		cur = cur->link;
	}
}
 
// Function to insert an element at the rear end
NODE insert_rear(int cf, int px, int py, int pz, NODE head)
{
	NODE temp, cur;
 
	temp=(NODE)malloc(sizeof(struct node));
	temp->cf = cf;
	temp->px = px;
	temp->py = py;
	temp->pz = pz;
	temp->link = NULL;
 
cur = head->link;
	while(cur->link != head)
	{
		cur = cur->link;
	}
	cur->link = temp;
	temp->link = head;
	return head;
 
  }
 
// Function to read a polynomial
 
/* Assumption: The terms in P(x,y,z) will be lexicographically ordered i.e. first we order the terms according to decreasing degrees in x; those with the same degree in x we order according to decreasing degrees in y; those with the same degrees in x and y we order according to decreasing degrees in z.
Example: The polynomial P(x,y,z) = 8x2y2z - 6yz8 + 3x3yz + 2 xy7z - 5x2y3 - 4xy7z3
needs to be read in the order P(x,y,z) = 3x3yz  - 5x2y3 + 8x2y2z - 4xy7z3+ 2 xy7z- 6yz8   */
 
NODE readpoly(NODE head)
{
	int n, i, cf, px,py,pz;
	printf("Enter the number of terms \n");
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
	{
		printf("Enter the coefficient of %d term\n",i);
		scanf("%d",&cf);
 
		printf("Enter the power of x of %d term\n",i);
		scanf("%d", &px);
		printf("Enter the power of y of %d term\n",i);
		scanf("%d", &py);
		printf("Enter the power of z of %d term\n",i);
		scanf("%d", &pz);
 
		head = insert_rear(cf, px, py, pz, head);
	}
	return head;
}
 
// Function to evaluate a polynomial
void evaluate(NODE head)
{
	NODE cur;
	int x,y,z,result=0;
	if(head->link == head)
	{
		printf("Polynomial does not exist\n");
		return;
	}
 
	printf("Enter the value of x\n");
	scanf("%d",&x);
	printf("Enter the value of y\n");
	scanf("%d",&y);
	printf("Enter the value of z\n");
	scanf("%d",&z);
 
	cur = head->link;
	while(cur != head)
	{
		result = result + cur->cf * pow(x, cur->px)* pow(y, cur->py)* pow(z, cur->pz);
		cur = cur->link;
	}
 
	printf("The result of evaluation is %d\n", result);
}
 
// Function to add 2 polynomials
NODE addpoly(NODE h1, NODE h2, NODE h3)
{
	int sumcf;
	NODE p1, p2;
	p1 = h1->link;
	p2 = h2->link;
 
while(p1 != h1 && p2 != h2)
	{
 
		if(p1->px > p2->px)
		{
			h3 = insert_rear(p1->cf, p1->px, p1->py, p1->pz, h3);
			p1 = p1->link;
		}
		else if(p1->px < p2->px)
		{
			h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
			p2 = p2->link;
		}
		else
		{
			if(p1->py > p2->py)
			{
				h3 = insert_rear(p1->cf, p1->px, p1->py, p1->pz, h3);
				p1 = p1->link;
			}
			else if(p1->py < p2->py)
			{
				h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
				p2 = p2->link;
			}
			else
			{
				if(p1->pz > p2->pz)
				{
					h3 = insert_rear(p1->cf, p1->px, p1->py, p1->pz, h3);
					p1 = p1->link;
				}
				else if(p1->pz < p2->pz)
				{
					h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
					p2 = p2->link;
				}
				else
				{
					sumcf = p1->cf + p2->cf;
					if(sumcf != 0)
					h3 = insert_rear(sumcf, p1->px, p1->py, p1->pz, h3);
					p1 = p1->link;
					p2 = p2->link;
 
				}
			}
		}
 
	}
 
	while(p1 != h1)
	{
		h3 = insert_rear(p1->cf, p1->px,p1->py,p1->pz,h3);
		p1 = p1->link;
	}
 
	while(p2 != h2)
	{
		h3 = insert_rear(p2->cf, p2->px,p2->py,p2->pz,h3);
		p2 = p2->link;
	}
	return h3;
}
 
void main( )
{
	NODE h1, h2, h3;
 
	h1 = (NODE)malloc(sizeof(struct node));
	h2 = (NODE)malloc(sizeof(struct node));
	h3 = (NODE)malloc(sizeof(struct node));
 
	h1->link = h1;
	h2->link = h2;
	h3->link = h3;
 
	printf("enter the first polynomial\n");
	h1 = readpoly(h1);
 
	printf("enter the second polynomial\n");
	h2 = readpoly(h2);
 
	h3 = addpoly(h1, h2, h3);
 
	printf("The first polynomial is\n");
	display(h1);
 
	printf("The second polynomial is\n");
	display(h2);
 
	printf("Their sum  is\n");
	display(h3);
	evaluate(h1);
}
