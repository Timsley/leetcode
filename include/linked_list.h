#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct ListNode {
    int val;
    struct ListNode *next;
};


#define LISTR_OK                              ((int)0)
#define LISTR_FAIL                            ((int)-1)

#define LINKED_LIST_CHK_FAIL(argu, value)     if(!(argu)) {printf("<LINKED_LIST> ERR : func=%s, line=%d, argument="#argu".\n", __func__, __LINE__); return value;}



extern void link_list_main_test(void);


#endif
