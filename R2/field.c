#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
  
  int result = value & (1 << position); //possibly position-1
  if(result != 0){
    return 1;
  }
  
  return 0;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
  int result = value | (1 << position); //possible pos-1
  
  return result;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
  
  int mask = 1 << position;
  
  
  int result = value ^ mask;
  
  return result;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {
  
  int val_adj = value >> lo;
  
  int mask = 1;
  mask = ~mask;
  mask = mask << (hi-lo);
  mask = ~mask;
  val_adj = val_adj & mask;
  
  if(!isSigned){
    return val_adj;
  }
  if(isSigned){
    //mask = ~mask;
    val_adj = val_adj |  mask;
    return ~val_adj;
  }
  
  
  return 0;
}
