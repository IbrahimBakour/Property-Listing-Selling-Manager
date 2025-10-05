#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct property *linker;

struct property {

	int propertyId, propertyType, bedrooms, bathrooms, districtNo;
	float houseSizeInSqft, priceOfProperty, noOfPerches, pricePerPerch, propertySizeInSqft;
	linker next;
  	char propertyAddress[100];
  	char ownerName[50];
	char ownerTelNo[20];
};
typedef struct{

	linker head, tail;

}list;
void initPropertyList(list *l){

	l->head = NULL;
	l->tail = NULL;

}
//1: this function used to add a new property
linker addNewProperty(){

	linker ptr = (linker)malloc(sizeof(struct property));

	printf("\n\t\tEnter property id : ");
	scanf("%d",&ptr->propertyId);
	printf("\n\t\t1.Sabah\n\t\t2.Selangor\n\t\t3.Terengganu\n\t\t4.Kedah\n\t\t5.Perlis\n\t\t6.Pahang\n\t\t7.Penang\n\t\t8.Malacca\n\t\t9.Sarawak\n\t\t10.Perak\n\t\t11.Johor\n\t\t11.Kelantan\n\t\t12.Negeri Sembilan\n\t\t13.Putrajaya\n");
	printf("\n\n\t\tEnter a number for the state below to list : ");
	scanf("%d",&ptr->districtNo);

	fflush(stdin);

	printf("\n\t\tEnter address of the property: ");
	scanf("%[^\n]s",&ptr->propertyAddress);

	fflush(stdin);

	printf("\n\t\tEnter the property owner's name: ");
	scanf("%[^\n]s",&ptr->ownerName);

	printf("\n\t\tEnter a contact number : ");
	scanf("%s",&ptr->ownerTelNo);

	printf("\n\t\tChoose property type from the list below.\n");
	printf("\n\t\t\t1.Residence\n\t\t\t2.Land\n\t\t\t3.Commercialno\n\t\t\t4.Industrial\n");
	printf("\n\t\tEnter property type : ");
    scanf("%d",&ptr->propertyType);

		if(ptr->propertyType == 1){
    		printf("\n\t\tEnter house size in squarefeet: ");
    		scanf("%f",&ptr->houseSizeInSqft);

			printf("\n\t\tEnter number of perches: ");
    		scanf("%f",&ptr->noOfPerches);

	 		printf("\n\t\tEnter price of the property: ");
	    	scanf("%f",&ptr->priceOfProperty);

	     	printf("\n\t\tEnter number of bedrooms: ");
	    	scanf("%d",&ptr->bedrooms);

			printf("\n\t\tEnter number of bathrooms: ");
	    	scanf("%d",&ptr->bathrooms);


		}else if(ptr->propertyType == 2){
			printf("\n\t\tEnter number of perches: ");
		   	scanf("%f",&ptr->noOfPerches);

		   	printf("\n\t\tEnter price per perch: ");
		   	scanf("%f",&ptr->pricePerPerch);


		}else if(ptr->propertyType == 3){
    		printf("\n\t\tEnter property size in squarefeet: ");
		   	scanf("%f",&ptr->propertySizeInSqft);

			printf("\n\t\tEnter number of perches: ");
		   	scanf("%f",&ptr->noOfPerches);

		    printf("\n\t\tEnter price of the property: ");
		    scanf("%f",&ptr->priceOfProperty);


		}else if(ptr->propertyType == 4){

			printf("\n\t\tEnter property size in squarefeet: ");
    	    scanf("%f",&ptr->propertySizeInSqft);

		    printf("\n\t\tEnter price of the property: ");
        	scanf("%f",&ptr->priceOfProperty);


     	}else{
     		printf("\n\t\tInvalid property type!");

		}


	ptr->next = NULL;
	return ptr;

}
//2: display if the insert has been successfully added or not
void InsertProp(list *l,linker ptr){

	if(ptr->propertyType <= 4){
		if(l->head == NULL){

			l->head = l->tail = ptr;
			printf("\n\t\t Property Is Inserted Successfully!\n\n");

		}else{

			ptr->next = l->head;
			l->head = ptr;
			printf("\n\t\tProperty Is Inserted Successfully!\n\n");

		}
	}else{
			printf("\n\t\t\" Property Insertion Is Failed!\"\n\n");
	}


}

//3: To search for a property
void searchProperty(list *l){ // search function to

	int position, found = 0;
	linker temp;
	temp = l->head;

	if(temp == NULL){

		printf("\n\t\t\"Property List is empty!\"\n\n\n");

	}else{

		printf("\n\t\tEnter the property id which you want to search: ");
        scanf("%d",&position);

        while(temp != NULL && (!found)){

			if(temp->propertyId == position){

        		found = 1;
			}else{

				temp = temp->next;
				found = 0;

			}
		}

		if(found){

			printf("\n\t\t\"Your Property Is Found At  %d.\"\n ",position);

		}else{

			 printf("\n\t\t\"Your Property Is Not Found!\"\n");

		}
	}
}
//4: To delete a property
void deleteProperty(list *l){

	linker ptr1, ptr2;
	int found = 0, position;

	ptr1 = l->head;
	ptr2 = ptr1;

	printf("\n\t\tEnter the property id which you want to delete from the list: ");
    scanf("%d",&position);

	while((!found) && (ptr1 != NULL)){

		if(ptr1->propertyId == position){

			found = 1;

		}else{

			ptr2 = ptr1;
			ptr1 = ptr1->next;

		}

	}

	if(found){

		if(ptr2 == ptr1){

			l->head = ptr2->next;
			printf("\n\t\tProperty deleted successfully!\n");

		}else if(ptr1 == l->tail){

			l->tail = ptr2;
			ptr2->next = NULL;
			printf("\n\t\tProperty deleted successfully!\n");

		}else{

			ptr2->next = ptr1->next;
			printf("\n\t\tProperty deleted successfully!\n");

		}

	}else{
			printf("\n\t\tProperty does not exists!\n");
	}
}
//5: To print a property
void displayProperty(linker ptr){

	printf("\n\t\t\t\t``````````````````````````````````````````````\n");
	if(ptr == NULL){
			printf("\n\t\t\t\t\"Property doesn't exist!\"\n");
	}else{
			printf("\n");
			printf("\t\t\t\tProperty Id = %d\n",ptr->propertyId);
	        printf("\t\t\t\tAddress of Property = %s\n",ptr->propertyAddress);
	        printf("\t\t\t\tProperty district id = %d\n",ptr->districtNo);
	        printf("\t\t\t\tOwner's Name = %s\n",ptr->ownerName);
            printf("\t\t\t\tOwner Telephone No = %s\n",ptr->ownerTelNo);
            printf("\t\t\t\tProperty Type = %d\n",ptr->propertyType);

		   	if(ptr->propertyType == 1){
				printf("\t\t\t\tHouse size in squarefeet = %.2f\n",ptr->houseSizeInSqft);
				printf("\t\t\t\tNumber of perches = %.2f\n",ptr->noOfPerches);
    	  		printf("\t\t\t\tPrice of the property = %.2f\n",ptr->priceOfProperty);
		    	printf("\t\t\t\tNumber of bedrooms = %d\n",ptr->bedrooms);
 				printf("\t\t\t\tNumber of bathrooms = %d\n",ptr->bathrooms);

			}else if(ptr->propertyType == 2){
				printf("\t\t\t\tNumber of perches = %.2f\n",ptr->noOfPerches);
    			printf("\t\t\t\tPrice per perch = %.2f\n",ptr->pricePerPerch);

			}else if(ptr->propertyType == 3){
				printf("\t\t\t\tProperty size in squarefeet = %.2f\n",ptr->propertySizeInSqft);
				printf("\t\t\t\tNumber of perches = %.2f\n",ptr->noOfPerches);
 			    printf("\t\t\t\tPrice of the property = %.2f\n",ptr->priceOfProperty);

			}else{
				printf("\t\t\t\tProperty size in squarefeet = %.2f\n",ptr->propertySizeInSqft);
				printf("\t\t\t\tPrice of the property = %.2f\n",ptr->priceOfProperty);

    		}
	}
}
//6: To show the properties list
void showProperties(list *l){
	linker ptr;
	ptr = l->head;

	if(ptr == NULL){
		printf("\n\t\t\t\t\"Property List is empty!\"\n\n\n");

	}else{

		printf("\n\t\t\t\t\"Show Property List!\"\n");

		while(ptr!= NULL){
			displayProperty(ptr);

			ptr=ptr->next;
		}
	}
}
//7: To filter under a specific state
void filterPropertyByLocation(list *l){

	linker ptr;
	ptr = l->head;
	int location;
	printf("\n\t\t1.Sabah\n\t\t2.Selangor\n\t\t3.Terengganu\n\t\t4.Kedah\n\t\t5.Perlis\n\t\t6.Pahang\n\t\t7.Penang\n\t\t8.Malacca\n\t\t9.Sarawak\n\t\t10.Perak\n\t\t11.Johor\n\t\t11.Kelantan\n\t\t12.Negeri Sembilan\n\t\t13.Putrajaya\n");
	printf("\n\t\t\t\tEnter the district id which you want to search in: ");
	scanf("%d",&location);

	if(ptr == NULL){
		printf("\n\t\t\t\t\"Property List is empty!\"\n\n\n");
	}else{
		while(ptr!= NULL){
				if(ptr->districtNo == location){
					displayProperty(ptr);
				}
			ptr = ptr->next;
		}
	}
}
//8 User Interface
void main (){
	system("COLOR 9");
	list *l;
	l = (list*)malloc(sizeof(list));
	initPropertyList(l);

    int choice =0;
    while(choice != 6){
		printf("\t\t********************************** Manage your PROPERTY with us! ***********************************\n");
        printf("\n\t\t\tWhat would like to do? Please choose one option from the following list.\n");
        printf("\t\t\t==================================================================\n");
        printf("\n\t\t\t\t1.Add Property\n"
		"\t\t\t\t2.Search for a Property\n\t\t\t\t3.Remove Property\n\t\t\t\t4.Display all properties\n\t\t\t\t5.Filter Properties by choosen location\n\t\t\t\t6.Exit\n");
        printf("\n\t\tEnter your choice : ");
        scanf("%d",&choice);
        printf("\n\t\t__________________________________________________________________________________________\n");

        switch(choice){
            case 1:
              	InsertProp(l, addNewProperty());     	break;
            case 2:
            	searchProperty(l);     	            	break;
            case 3:
            	deleteProperty(l);                     	break;
            case 4:
            	showProperties(l);		            	break;
            case 5:
            	filterPropertyByLocation(l);           	break;
            case 6:
            	exit(0);        		            	break;
            default:
            	printf("\n\n\t\t\t\t\tPlease enter valid choice number :)\n\n");
        }
    }
}



