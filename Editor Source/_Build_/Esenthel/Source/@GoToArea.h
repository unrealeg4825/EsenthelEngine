﻿/******************************************************************************/
/******************************************************************************/
class GoToArea : ClosableWindow
{
   Text     tx, tz;
   TextLine  x,  z;
   Button   go;

   static void Go(GoToArea &go_to);

   void create();
   virtual GoToArea& show()override;
   virtual void update(C GuiPC &gpc)override;
};
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
