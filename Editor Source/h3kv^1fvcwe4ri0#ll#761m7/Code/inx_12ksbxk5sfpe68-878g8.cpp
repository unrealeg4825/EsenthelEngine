/******************************************************************************/
Cipher1 SettingsCipher(175, 17, 65, 221, 208, 126, 106, 23, 147, 207, 38, 253, 227, 68, 125, 160, 129, 82, 203, 26, 88, 45, 68, 207, 15, 247, 223, 55, 201, 117, 223, 154, 172, 189, 57, 175, 30, 97, 128, 99, 212, 214, 12, 144, 86, 103, 218, 115, 150, 95, 31, 234, 96, 68, 41, 95, 169, 222, 229, 181, 130, 186, 228, 136, 251, 54, 207, 146, 160, 145, 33, 129, 236, 13, 181, 102, 100, 55, 81, 164, 10, 118, 58, 236, 201, 24, 139, 26, 244, 190, 255, 21, 239, 82, 45, 178, 122, 113, 157, 178, 225, 102, 196, 85, 105, 28, 165, 40, 214, 253, 201, 125, 65, 131, 168, 12, 181, 59, 155, 42, 235, 206, 185, 40, 81, 109, 249, 90, 116, 209, 121, 102, 66, 38, 97, 51, 15, 218, 33, 174, 242, 181, 91, 203, 104, 65, 178, 168, 33, 60, 3, 45, 164, 237, 121, 140, 169, 236, 95, 118, 86, 29, 79, 53, 10, 1, 160, 140, 52, 131, 181, 110, 168, 143, 1, 84, 84, 24, 165, 149, 128, 216, 107, 218, 78, 201, 238, 208, 67, 131, 23, 186, 65, 159, 40, 244, 1, 168, 22, 96, 215, 113, 80, 139, 210, 43, 54, 144, 111, 58, 250, 64, 17, 220, 227, 229, 128, 216, 220, 174, 122, 253, 32, 168, 101, 84, 155, 4, 74, 179, 177, 84, 131, 213, 153, 113, 249, 125, 162, 243, 3, 117, 232, 123, 170, 159, 147, 118, 3, 96, 184, 201, 189, 33, 114, 179);
/******************************************************************************/
bool SaveSettings(File &f)
{
   {
      ChunkWriter cw(f);
      if(File *f=cw.beginChunk("Users", 0))
      {
         Save(*f, Users);
      }
      if(File *f=cw.beginChunk("Settings", 0))
      {
         f.putBool(AllowUserRegistration());
      }
   }
   return f.ok();
}
bool LoadSettings(File &f)
{
   ChunkReader cr; if(cr.read(f))
   {
      for(; File *f=cr(); )
      {
         if(cr.name()=="Users")switch(cr.ver())
         {
            case 0: Load(*f, Users); break;
         }else 
         if(cr.name()=="Settings")switch(cr.ver())
         {
            case 0: AllowUserRegistration.set(f.getBool()); break;
         }
      }
      return true;
   }
   return false;
}
/******************************************************************************/
bool SaveSettings(C Str &name="Server Settings")
{
   File f; if(SaveSettings(f.writeMem()))
   {
      f.pos(0); return SafeOverwrite(f, name, null, &SettingsCipher);
   }
   return false;
}
bool LoadSettings(C Str &name="Server Settings")
{
   File f; if(f.readStdTry(name, &SettingsCipher))return LoadSettings(f);
   return false;
}
/******************************************************************************/
