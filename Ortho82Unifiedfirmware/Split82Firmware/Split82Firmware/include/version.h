/*
 * version.h
 *
 * Created: 12/11/2024 18:04:18
 *  Author: neeraj
 */ 


#ifndef VERSION_H_
#define VERSION_H_

const int MAJOR = 0;
const int MINOR = 0;
const int PATCH = 0;

char* get_semantic_version(void);

#ifdef _DEBUG
const char TIMESTAMP[17] = "2024-11-12_180850"
char* get_timestamp(void);
#endif // _DEBUG




#endif /* VERSION_H_ */