/******************************************************************************/
@interface MyOpenGLView : NSView
{
}
-(void) mouseDown:(NSEvent*)theEvent;
-(void) mouseUp  :(NSEvent*)theEvent;
@end
/******************************************************************************/
namespace EE{
/******************************************************************************/
extern MyOpenGLView *OpenGLView;
/******************************************************************************/
}
/******************************************************************************/
