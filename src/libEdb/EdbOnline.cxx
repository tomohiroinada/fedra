//-- Author :  Valeri Tioukov   27.06.2000
 
//////////////////////////////////////////////////////////////////////////
//                                                                      //
// EdbOnline                                                            //
//                                                                      //
// head Edb class for online data taking                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <string.h>

#include "TSystem.h"

#ifndef ROOT_EdbOnline
#include "EdbOnline.h"
#endif

//ClassImp(EdbOnline)

//______________________________________________________________________________
EdbOnline::EdbOnline( char *name, char *title ) 
: TROOT(name, title)
{
  //  Init();
}

//______________________________________________________________________________
EdbOnline::~EdbOnline()
{
  if( eRun )  delete eRun;
}

//______________________________________________________________________________
void EdbOnline::Init()
{
  SetDataDirectory(   gSystem->ExpandPathName("$(SCAN_DATA)")   );
  SetOnlineDirectory( gSystem->ExpandPathName("$(SCAN_ONLINE)") );

  eRunID  = -1;

  ReadParametersDB();

  if( eRunID<0 ) eRunID=0;

  WriteParametersDB();

  eRun =  new EdbRun( GetRunID(), "RECREATE", eDataDirectory.Data() );

  ReadParameters();

  TString logfile(eOnlineDirectory);
  logfile.Append("/runs.log");

  eRun->PrintLog( logfile.Data() );
}

//______________________________________________________________________________
void EdbOnline::Print( Option_t *opt ) const
{
  //  eRun->Print();
  printf( "Online directory: %s\n",   eOnlineDirectory.Data() );
  printf( "Data directory:   %s\n",   eDataDirectory.Data()   );
}

//______________________________________________________________________________
void  EdbOnline::WriteParametersDB()
{
  TString mem(eOnlineDirectory);
  mem.Append("/scan.mem");

  FILE *fp=fopen( mem.Data() , "w" );
  if (fp==NULL)   
    {
      printf("ERROR: enable to open file: %s for writing\n", mem.Data() );
      return;
    }
  else
    {
      fprintf( fp, "# DO NOT EDIT THIS FILE!\n");
      fprintf( fp, "LASTRUN %d", GetRunID() );
    }

  fclose(fp);

}

//______________________________________________________________________________
int  EdbOnline::ReadParametersDB()
{
  TString mem(eOnlineDirectory);
  mem.Append("/scan.mem");
  return  ReadParameters( mem.Data() );
}

//______________________________________________________________________________
int  EdbOnline::ReadParameters()
{
  TString par(eOnlineDirectory);
  par.Append("/scan.par");
  return  ReadParameters( par.Data() );
}

//______________________________________________________________________________
int  EdbOnline::ReadParameters( const char *file )
{
  char            buf[256];
  char            key[256];
  char            name[256];

  FILE *fp=fopen(file,"r");
  if (fp==NULL)   {
    printf("ERROR: enable to open file: %s \n", file);
    return(-1);
  }else
    printf( "\nRead parameters from file: %s\n\n", file );

  while( fgets(buf,256,fp)!=NULL ) {

    for( int i=0; i<(int)strlen(buf); i++ ) 
      if( buf[i]=='#' )  {
	buf[i]='\0';                       // cut out comments starting from #
	break;
      }

    if( sscanf(buf,"%s",key)!=1 )                             continue;

    if      ( !strcmp(key,"RUNNAME")   )
      {
	sscanf(buf+strlen(key),"%s",name);
	GetRun()->GetHeader()->SetName( name );
      }
    else if ( !strcmp(key,"RUNTITLE")  )
      {
	GetRun()->GetHeader()->SetTitle( buf+strlen(key) );
      }
    else if ( !strcmp(key,"CCD")       )
      {
	GetRun()->GetHeader()->GetStage()->GetCCD()->ReadParameters( buf+strlen(key) );
      }
    else if ( !strcmp(key,"OBJECTIVE") )
      {
	GetRun()->GetHeader()->GetStage()->GetObjective()->ReadParameters( buf+strlen(key) );
      }
    else if ( !strcmp(key,"AREA")      )
      {
	GetRun()->GetHeader()->GetArea()->ReadParameters( buf+strlen(key) );
      }
    else if ( !strcmp(key,"PLATE")     )
      {
	GetRun()->GetHeader()->GetPlate()->ReadParameters( buf+strlen(key) );
      }
    else if ( !strcmp(key,"PREDICTIONS")     )
      {
	sscanf(buf+strlen(key),"%s",name);
	GetRun()->GetPredictions()->ReadDC(name);
      }
    else if ( !strcmp(key,"FIDUCIALS")     )
      {
	sscanf(buf+strlen(key),"%s",name);
	GetRun()->GetMarks()->ReadDA(name);
      }

    else if ( !strcmp(key,"LASTRUN")     )
      {
	sscanf( buf+strlen(key),"%d", &eRunID );
	eRunID++;
      }

  }

  fclose(fp);

  return 0;
}




