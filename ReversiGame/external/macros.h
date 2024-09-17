#pragma once

//to increment if needed
#define SAFE_DELETE(pPtr) {if(pPtr){delete pPtr;pPtr=NULL;}}
