﻿/******************************************************************************/
class EditObjTypeClass : Enum
{
   Memc<Memc<GuiEditParam> > params;

   EditObjTypeClass();
 C Memc<GuiEditParam>* findParams(C UID &type_id);
};
/******************************************************************************/
/******************************************************************************/
extern EditObjTypeClass EditObjType;
/******************************************************************************/
