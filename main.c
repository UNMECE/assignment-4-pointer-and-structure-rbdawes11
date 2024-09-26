#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
	for(index = 0; index < 5; index++)
	{
		if(index == 0)
        {
		    item_list[index].price = 1.99;
		    char item1Sku[50] = "12345";
		    item_list[index].sku = (char *) malloc(sizeof(char) * strlen(item1Sku));
		    strcpy(item_list[index].sku, item1Sku);
		    char item1Cat[50] = "Candy";
		    item_list[index].category = (char *) malloc(sizeof(char) * strlen(item1Cat));
		    strcpy(item_list[index].category, item1Cat);
		    char item1Name[50] = "Reese's";
		    item_list[index].name = (char *) malloc(sizeof(char)*strlen(item1Name));
		    strcpy(item_list[index].name, item1Name);
		}
		else if(index == 1)
        {
            item_list[index].price = 3.99;
            char item2Sku[50] = "23456";
            item_list[index].sku = (char *) malloc(sizeof(char) * strlen(item2Sku));
            strcpy(item_list[index].sku, item2Sku);
            char item2Cat[50] = "Cereal";
            item_list[index].category = (char *) malloc(sizeof(char) * strlen(item2Cat));
            strcpy(item_list[index].category, item2Cat);
            char item2Name[50] = "Captain Crunch";
            item_list[index].name = (char *) malloc(sizeof(char)*strlen(item2Name));
            strcpy(item_list[index].name, item2Name);
		}
		else if(index == 2)
        {
            item_list[index].price = 2.49;
            char item3Sku[50] = "34567";
            item_list[index].sku = (char *) malloc(sizeof(char) * strlen(item3Sku));
            strcpy(item_list[index].sku, item3Sku);
            char item3Cat[50] = "Hygiene";
            item_list[index].category = (char *) malloc(sizeof(char) * strlen(item3Cat));
            strcpy(item_list[index].category, item3Cat);
            char item3Name[50] = "Toothpaste";
            item_list[index].name = (char *) malloc(sizeof(char)*strlen(item3Name));
            strcpy(item_list[index].name, item3Name);
        }
		else if(index == 3)
        {
            item_list[index].price = 2.99;
            char item4Sku[50] = "45678";
            item_list[index].sku = (char *) malloc(sizeof(char) * strlen(item4Sku));
            strcpy(item_list[index].sku, item4Sku);
            char item4Cat[50] = "Breakfast";
            item_list[index].category = (char *) malloc(sizeof(char) * strlen(item4Cat));
            strcpy(item_list[index].category, item4Cat);
            char item4Name[50] = "Oatmeal";
            item_list[index].name = (char *) malloc(sizeof(char)*strlen(item4Name));
            strcpy(item_list[index].name, item4Name);
        }
		else if(index == 4)
        {
            item_list[index].price = 1.49;
            char item5Sku[50] = "56789";
            item_list[index].sku = (char *) malloc(sizeof(char) * strlen(item5Sku));
            strcpy(item_list[index].sku, item5Sku);
            char item5Cat[50] = "Drink";
            item_list[index].category = (char *) malloc(sizeof(char) * strlen(item5Cat));
            strcpy(item_list[index].category, item5Cat);
            char item5Name[50] = "Coke Zero Sugar";
            item_list[index].name = (char *) malloc(sizeof(char)*strlen(item5Name));
            strcpy(item_list[index].name, item5Name);
        }
		else
        {
		}
	}
}

void free_items(Item *item_list, int size)
{
    for(int i = 0; i < size; i++)
    {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size)
{
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += item_list[i].price;
    }
    double Average = sum/size;

    return Average;
}

void print_items(Item *item_list, int size)
{
        for(int i = 0; i < size; i++)
        {
            printf("\n#################\n");
            printf("Item Name: ");
            for(int j = 0; item_list[i].name[j] != '\0'; j++)           
             printf("%c", item_list[i].name[j]);
            printf("\nItem Sku: ");
            for(int k = 0; item_list[i].sku[k] != '\0'; k++)           
             printf("%c", item_list[i].sku[k]);
            printf("\nItem Category: ");
            for(int l = 0; item_list[i].category[l] != '\0'; l++)           
             printf("%c", item_list[i].category[l]);
            printf("\nItem Price: %.2f", item_list[i].price);
        }
        printf("\n#################\n");
}

int main(int argc, char *argv[])
{
	Item *item_list = (Item *) malloc(sizeof(Item) * 5);
    int index;
    add_item(item_list, item_list->price, item_list->sku, item_list->category, item_list->name, index);
	print_items(item_list, 5);
    printf("\nThe average price of these items is: %.2f\n", average_price(item_list, 5));
    
    int ct = 0, size = 5;
    char sku[10];
    strcpy(sku, argv[1]);
    printf("\nChecking for the SKU you entered:\n");
    while(ct < size && strcmp(item_list[ct].sku,sku) != 0)
    {
        printf("...\n");
        ct++;
    }
    if (ct < size) {
        printf("Your item with the matching SKU was found!\n");
        printf("Item Name: %s\n", item_list[ct].name);
        printf("Item Category: %s\n", item_list[ct].category);
        printf("Item Price: %.2f\n", item_list[ct].price);
    } else {
        printf("SKU '%s' not found.\n", sku);
    }

    free_items(item_list, 5);

    return 0;
}
