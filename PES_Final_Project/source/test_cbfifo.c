/*
 * cbfifo_testcase.h
 *
 *      Author: Howdy
 */
/*******************************************************************************
Header files
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "cbfifo.h"
#include "uart.h"
#include "fsl_debug_console.h"
/*******************************************************************************
GLobal variables
*******************************************************************************/
int g_tests_passed = 0;
int g_tests_total = 0;

circular_queue cb_test = {.head = 0, .tail = 0,};
/*******************************************************************************
Function macro
*******************************************************************************/
#define test_assert(value) {                                            \
  g_tests_total++;                                                      \
  if (value) {                                                          \
    g_tests_passed++;                                                   \
  } else {                                                              \
    PRINTF("ERROR: test failure at line %d\n", __LINE__);               \
  }                                                                     \
}

#define test_equal(value1, value2) {                                    \
  g_tests_total++;                                                      \
  long res1 = (long)(value1);                                           \
  long res2 = (long)(value2);                                           \
  if (res1 == res2) {                                                   \
    g_tests_passed++;                                                   \
  } else {                                                              \
    PRINTF("ERROR: test failure at line %d: %ld != %ld\r\n", __LINE__, res1, res2); \
  }                                                                     \
}

/*******************************************************************************
Header files
*******************************************************************************/
/*******************************************************************************
* @Function Name: test_cbfifo_one_iteration
* @Description: consists of various test cases which will be executed
* @input param : None
* @return: None
*******************************************************************************/
static void test_cbfifo_one_iteration()
{
  char *str ="To be, or not to be: that is the question:\n"
    "Whether 'tis nobler in the mind to suffer\n"
    "The slings and arrows of outrageous fortune,\n"
    "Or to take arms against a sea of troubles,\n"
    "And by opposing end them? To die, to sleep--\n"
    "No more--and by a sleep to say we end\n"
    "The heart-ache and the thousand natural shocks\n"
    "That flesh is heir to, 'tis a consummation\n"
    "Devoutly to be wish'd. To die, to sleep;\n"
    "To sleep: perchance to dream: ay, there's the rub;\n"
    "For in that sleep of death what dreams may come\n"
    "When we have shuffled off this mortal coil,\n"
    "Must give us pause.";

  char buf[1024];    //prof
  const int cap = cbfifo_capacity(&cb_test);
  assert(strlen(str) >= cap*2);
  assert(sizeof(buf) > cap);
  test_equal(cbfifo_length(&cb_test), 0);
  test_equal(cbfifo_dequeue(&cb_test,buf, cap), 0);
  test_equal(cbfifo_dequeue(&cb_test,buf, 2), 0);
  test_equal(cbfifo_enqueue(&cb_test,str, 0), 0);

}

/*******************************************************************************
* @Function Name: test_cbfifo
* @Description: executes the test cycle
* @input param : None
* @return: None
*******************************************************************************/
void test_cbfifo()
{
  g_tests_passed = 0;
  g_tests_total = 0;

  test_cbfifo_one_iteration();

  PRINTF("%s: passed %d/%d test cases\r\n", __FUNCTION__,
      g_tests_passed, g_tests_total);
}
