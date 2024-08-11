#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct node
{
    int coeff;
    int expo;
    struct node *next;
};

typedef struct node node;

// Function to insert a term into a linked list
node *insertNode(node *head, int coeff, int expo)
{
    node *term = (node *)malloc(sizeof(node));
    term->coeff = coeff;
    term->expo = expo;
    term->next = NULL;

    // Creating the polynomial in sorted order (descending order of exponent)
    if (head == NULL || expo > (head->expo))
    {
        term->next = head;
        head = term;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL && ptr->next->expo >= expo)
        {
            ptr = ptr->next;
        }
        term->next = ptr->next;
        ptr->next = term;
    }
    return head;
}
// Function to add two polynomials
node *addPoly(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *head3 = NULL;
    int expo, coeff;

    //node *result = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {

        if (ptr1->expo > ptr2->expo)
        {
            head3 = insertNode(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = insertNode(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
        else
        {
            head3 = insertNode(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insertNode(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = insertNode(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    return head3;
}

// Function to display a polynomial
void displayPoly(node *head)
{
    if (head == NULL)
    {
        printf("0");
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *result = NULL;
    int n1, n2, coeff1, expo1, coeff2, expo2;

    printf("Enter the number of terms in polynomial 1:\n");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the coefficient of term %d:\n", i + 1);
        scanf("%d", &coeff1);
        printf("Enter the exponent of term %d:\n", i + 1);
        scanf("%d", &expo1);
        head1 = insertNode(head1, coeff1, expo1);
    }

    printf("Enter the number of terms in polynomial 2:\n");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the coefficient of term %d:\n", i + 1);
        scanf("%d", &coeff2);
        printf("Enter the exponent of term %d:\n", i + 1);
        scanf("%d", &expo2);
        head2 = insertNode(head2, coeff2, expo2);
    }

    printf("Polynomial 1:\n");
    displayPoly(head1);

    printf("Polynomial 2:\n");
    displayPoly(head2);

    result = addPoly(head1, head2);

    printf("Result Polynomial :\n");
    displayPoly(result);
    return 0;
}
