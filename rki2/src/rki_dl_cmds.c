#include <stdio.h>
#include <string.h>

#ifdef RKI_INCLUDE_DL_CMDS

#include <rtems/shell.h>
#include <rtems/rtl/dlfcn-shell.h>
#include <dlfcn.h>
#include <rtems/rtl/rap-shell.h>
#include <rtems/rtl/rtl-shell.h>

typedef void (*call_t)(void);

/*
** Dynamic load command 
*/
int dl_load_and_start_cfe( int argc, char *argv[])
{
   void*  handle;
   call_t call;
   int    call_ret;
   int    unresolved;
   char*  message = "loaded";

   handle = dlopen ("/cf/apps/cfe-core.o", RTLD_NOW | RTLD_GLOBAL);
   if (!handle)
   {
     printf("dlopen failed: %s\n", dlerror());
     return 1;
   }

   if (dlinfo (handle, RTLD_DI_UNRESOLVED, &unresolved) < 0)
   {
     message = "dlinfo error checking unresolved status";
   }
   else if (unresolved)
   {
     message = "has unresolved externals";
   }
   printf ("handle: %p %s\n", handle, message);

   call = dlsym (handle, "goCFE");
   if (call == NULL)
   {
     printf("dlsym failed: symbol start_cfe not found\n");
     return 1;
   }
   else
   {
      printf("dlsym OK: symbol start_cfe found\n");
   }

#if 1
   call ();
#endif

#if 0
   if (dlclose (handle) < 0)
   {
     printf("dlclose failed: %s\n", dlerror());
     return 1;
   }

   printf ("handle: %p closed\n", handle);
#endif

   return(call_ret);
}

/*
** Add the DL commands to the shell
*/
void rki_add_dl_commands(void)
{
   rtems_shell_add_cmd("dlopen","misc","dynamic loader dlopen",shell_dlopen);
   rtems_shell_add_cmd("dlclose","misc","dynamic loader dlclose",shell_dlclose);
   rtems_shell_add_cmd("dlsym","misc","dynamic loader dlsym",shell_dlsym);
   rtems_shell_add_cmd("dlcall","misc","dynamic loader dlcall",shell_dlcall);

   rtems_shell_add_cmd("rap","misc","dynamic loader rap command",shell_rap);

   rtems_shell_add_cmd("rtl","misc","dynamic loader rtl command",rtems_rtl_shell_command);

   rtems_shell_add_cmd("startcfedl","misc","Load and start the cFE Core",dl_load_and_start_cfe);
   
}
#else
/*
** no DL commands 
*/
void rki_add_dl_commands(void)
{
   return;
}
#endif
