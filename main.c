#include "myheader.h"

int main(int argc,char *argv[])
{
    int i, size, n;
    int option, choice;
    char *inputFile;
    INTNODE *dataList = NULL;

    SEGMENTBLOCK *s_blockHead = NULL;
    VITUALMEMPAGEBLOCKS *virtmempageBlocks = NULL;
    MEMPAGEBLOCKS *mempageBlocks = NULL;
    MEMSEGMENTBLOCKS *memSegBlocksHead = NULL;  
    
    while(choice!=5){
        printf("-----------------MENU---------------------\n");
        printf("1.Enter the data through a file\n");
        printf("2.Enter the data through the console\n");
        printf("3.Implementation of Paging on the data\n");
        printf("4.Implementation of Segmentation on data\n");
        printf("5.Exit the application\n");
        printf("------------------------------------------\n");
        printf("Your Choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the name of the file:");
            scanf("%s", inputFile);
            dataList = getProcessData(inputFile);
            break;
            case 2:
            printf("Enter the number of processes:");
            scanf("%d", &n);
            printf("Enter the process memory size in bytes:\n");
            for(i=0 ; i<n ; i++){
                printf("Process%d:", i+1);
                scanf("%d", &size);
                intInsertAtEnd(i+1, &(dataList));
                intInsertAtEnd(size, &(dataList));
            }
            break;
            case 3:
            if(dataList!=NULL){
                AllocatePAGING(s_blockHead, virtmempageBlocks, mempageBlocks, dataList);
            } else {
                printf("\n\nerr:Please enter some valid process data first...\n\n");
            }
            break;
            case 4:
            if(dataList!=NULL){
                AllocateSEGMENTATION(s_blockHead, memSegBlocksHead, dataList);
            } else {
                printf("\n\nerr:Please enter some valid process data first...\n\n");
            }
            break;
            case 5:
                printf("Bye!");
            break;
            default:
            printf("Invalid input provided to the program....\n");
            break;    
        }
    }      
    return 0;
}
