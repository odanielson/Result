#ifndef RESULT_H
#define RESULT_H

typedef enum _Status {
    OK,     // OK is deliberatly placed at value False to avoid usage patterns
            // like if((res=function()).status)
    ERROR,
} Status;

typedef struct _Result {
    void *handle;
    Status status;
} Result;

#endif
