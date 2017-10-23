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
    
    printf("Specify the type of input:\n1.File Input\n2.Console Input\nChoice:");
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
        default:
            printf("Error in taking the input data....\n");
    }
    if(dataList != NULL){
        printf("MENU\n1.Paging\n2.Segmentation\nChoice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                AllocatePAGING(s_blockHead, virtmempageBlocks, mempageBlocks, dataList);
            break;
            case 2:
                AllocateSEGMENTATION(s_blockHead, memSegBlocksHead, dataList);
            break;
            default:
            printf("Error to implement algorithms,command arguments error....\n");
        } 
    }         
    return 0;
}
