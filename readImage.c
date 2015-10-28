#include <Python.h>
//#include "./readbmp.c"


static PyObject* readImage(PyObject* self,PyObject *args)
{
    char* str, *CSV;
//    long filestart,fileend;
    unsigned char imagedata[54];
    int bytevalue,index=0;
    int width, height;

    if(!PyArg_ParseTuple(args, "s", &str)){return NULL;}

    FILE* image = fopen(str, "rb");
    do{

        bytevalue = fgetc(image);
        imagedata[index]= bytevalue;
        index++;
        if(index==54)break;
    }while(bytevalue != EOF);

int i =0;
width = imagedata[19]*256+imagedata[18];
height = imagedata[23]*256+imagedata[22];
int bits = imagedata[28];
//printf("%i %i %i \n", bits, width, height);

//    unsigned char imageArr[width*height];
    index =0;
    unsigned char wht =255, blk = 0;

    CSV = "ImageCSV.csv";

    FILE * fp = fopen(CSV,"w");
    do{

        bytevalue = fgetc(image);
        if(bytevalue==wht)
            fprintf(fp,"0,outside\n");
        else
            fprintf(fp,"1,border\n");

        index++;
//        if(index==54)break;
    }while(bytevalue != EOF);
fclose(fp);
fclose(image); //close the file


//    printf("%s", str);
    printf("C has processed the Image\n");
    return Py_BuildValue("s", CSV);
}



//static char helloworld_docs[] =
//    "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef readImage_funcs[] = {
    {"readImage", (PyCFunction)readImage,
     METH_VARARGS, NULL},
    {NULL}
};

void initreadImage(void)
{
    Py_InitModule3("readImage", readImage_funcs,
                   NULL);
}

