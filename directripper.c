#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "lame.h"
int main(){
  int numOfTracks;
  DIR  *dip;
  
  if ((dip = opendir("/run/user/1000/gvfs/cdda:host=sr0")) == NULL)
  {         
     printf("[-] Audio Disc is not found on sr0. \n");
  }
  else {
      printf("[+] Audio CD Found \n");
      FILE *fp = popen("cd /run/user/1000/gvfs/cdda:host=sr0 && ls | wc -l", "r");
      fscanf(fp, "%d", &numOfTracks);
      pclose(fp);
      closedir(dip);
      printf("[*] Number Of Tracks: %d \n", numOfTracks);
      DirectRip(numOfTracks);
	}
}

int DirectRip(int numOfTracks){
   printf("[+] Ripping started! \n");
   printf("[*] The ripped files are located into the 'Music' directory. ");
   system("cd /run/user/1000/gvfs/cdda:host=sr0 && ls | wc -l && cp * $HOME/Music");
   printf("[+] Ripping finished! \n");
}

