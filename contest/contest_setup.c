#include "contest.h"

#include "dberror.h"

#include "storage_mgr.h"
#include "buffer_mgr.h"
#include "record_mgr.h"
#include "btree_mgr.h"

/* set up record, buffer, pagefile, and index managers */
RC
setUpContest (int numPages)
{
    int a = numPages/10*7;
    int b = numPages - a;
  initRecordManager(&a);
    initIndexManager(&b);
  return RC_OK;
}

/* shutdown record, buffer, pagefile, and index managers */
RC
shutdownContest (void)
{
  shutdownRecordManager();
  return RC_OK;
}

/* return the total number of I/O operations used after setUpContest */
long
getContestIOs (void)
{
    return bTreeNumIO() + recordNumIO();
}
