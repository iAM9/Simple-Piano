#pragma comment(lib, "alut.lib")
#pragma comment(lib, "OpenAl32.lib")

#include<Windows.h>
#include<AL\al.h>
#include<AL\alc.h>
#include<AL\alut.h>

HINSTANCE hi;

////////////////////////////////	MIDDLE 'C' KEYS //////////////////////////////////////
ALuint Buffer_C, Source_C;		
ALuint Buffer_D, Source_D;					
ALuint Buffer_E, Source_E;				
ALuint Buffer_F, Source_F;		//	WHITE
ALuint Buffer_G, Source_G;				
ALuint Buffer_A, Source_A;
ALuint Buffer_B, Source_B;					
ALuint Buffer_C1, Source_C1;

ALuint Buffer_C_sharp, Source_C_sharp;
ALuint Buffer_D_sharp, Source_D_sharp;	//	BLACK
ALuint Buffer_F_sharp, Source_F_sharp;
ALuint Buffer_G_sharp, Source_G_sharp;
ALuint Buffer_A_sharp, Source_A_sharp;
////////////////////////////////	MIDDLE 'C' KEYS //////////////////////////////////////

////////////////////////////////	LOWER KEYS //////////////////////////////////////
ALuint Buffer_C_1, Source_C_1;		
ALuint Buffer_D_1, Source_D_1;					
ALuint Buffer_E_1, Source_E_1;				
ALuint Buffer_F_1, Source_F_1;		//	WHITE
ALuint Buffer_G_1, Source_G_1;				
ALuint Buffer_A_1, Source_A_1;
ALuint Buffer_B_1, Source_B_1;					
ALuint Buffer_B_1_1, Source_B_1_1;

ALuint Buffer_C_1_sharp, Source_C_1_sharp;
ALuint Buffer_D_1_sharp, Source_D_1_sharp;	//	BLACK
ALuint Buffer_F_1_sharp, Source_F_1_sharp;
ALuint Buffer_G_1_sharp, Source_G_1_sharp;
ALuint Buffer_A_1_sharp, Source_A_1_sharp;
////////////////////////////////	LOWER KEYS //////////////////////////////////////
ALfloat ListenerPos[] = {0,0,0};
ALfloat ListenerVel[] = {0,0,0};
ALfloat ListenerOri[] = {0,0,-1,0,0,1};
ALfloat SourcePos[] = {0,0,0};
ALfloat SourceVel[] = {0,0,0};

////////////////////////////////	MIDDLE 'C' KEYS //////////////////////////////////////
HBITMAP hBmp_key_C_sharp, hBmp_key_D_sharp, hBmp_key_F_sharp, hBmp_key_G_sharp, hBmp_key_A_sharp;				//	BLACK
HBITMAP hBmp_key_C, hBmp_key_D, hBmp_key_E, hBmp_key_F, hBmp_key_G, hBmp_key_A, hBmp_key_B, hBmp_key_C1;		//	WHITE

HWND window,exit_button;
HWND key_C, key_D, key_E, key_F, key_G, key_A, key_B, key_C1;			//	WHITE
HWND key_C_sharp, key_D_sharp,key_F_sharp,key_G_sharp,key_A_sharp;		//	BLACK
////////////////////////////////	MIDDLE 'C' KEYS //////////////////////////////////////

//////////////////// LOWER OCATAVE KEYS /////////////////////////////////
HBITMAP hBmp_key_C_1_sharp, hBmp_key_D_1_sharp, hBmp_key_F_1_sharp, hBmp_key_G_1_sharp, hBmp_key_A_1_sharp;					//	BLACK
HBITMAP hBmp_key_C_1, hBmp_key_D_1, hBmp_key_E_1, hBmp_key_F_1, hBmp_key_G_1, hBmp_key_A_1, hBmp_key_B_1, hBmp_key_B_1_1;	//	WHITE

HWND key_C_1, key_D_1, key_E_1, key_F_1, key_G_1, key_A_1, key_B_1, key_B_1_1;	//	WHITE	
HWND key_C_1_sharp, key_D_1_sharp,key_F_1_sharp,key_G_1_sharp,key_A_1_sharp;	//	BLACK
//////////////////// LOWER OCATAVE KEYS /////////////////////////////////

ALboolean LoadALData()
{
	ALenum format;
	ALsizei freq;
	ALvoid* data;
	ALsizei size;
	ALboolean loop;
	/////////////////////////////////////////////////////////////////
	///////////////////////// MIDDLE 'C' KEYS ///////////////////////
	//////////////////////////////////////////////////////////////////
	/////////////////////////////  key_C  ////////////////////////////

	alGenBuffers(1,&Buffer_C);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_C!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/C.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_C,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_C);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_C!",L"Error",MB_OK);
	}

	alSourcei( Source_C, AL_BUFFER,      Buffer_C);
	alSourcef( Source_C, AL_PITCH,       1.0);
	alSourcef( Source_C, AL_GAIN,        1.0);
	alSourcefv(Source_C, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_C, AL_POSITION,    SourcePos);
	alSourcei(Source_C, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_C  ////////////////////////////

	/////////////////////////////  key_C_sharp  ////////////////////////////

	alGenBuffers(1,&Buffer_C_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_C_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/C#.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_C_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_C_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_C_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_C_sharp, AL_BUFFER,      Buffer_C_sharp);
	alSourcef( Source_C_sharp, AL_PITCH,       1.0);
	alSourcef( Source_C_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_C_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_C_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_C_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_C_sharp  ////////////////////////////

	/////////////////////////////  key_D  ////////////////////////////
	alGenBuffers(1,&Buffer_D);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_D!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/D.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_D,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_D);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_D!",L"Error",MB_OK);
	}

	alSourcei( Source_D, AL_BUFFER,      Buffer_D);
	alSourcef( Source_D, AL_PITCH,       1.0);
	alSourcef( Source_D, AL_GAIN,        1.0);
	alSourcefv(Source_D, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_D, AL_POSITION,    SourcePos);
	alSourcei(Source_D, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_D  ////////////////////////////

	/////////////////////////////  key_D_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_D_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_D_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/D#.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_D_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_D_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_D_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_D_sharp, AL_BUFFER,      Buffer_D_sharp);
	alSourcef( Source_D_sharp, AL_PITCH,       1.0);
	alSourcef( Source_D_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_D_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_D_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_D_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_D_sharp  ////////////////////////////

	/////////////////////////////  key_E  ////////////////////////////
	alGenBuffers(1,&Buffer_E);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_E!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/E(1).wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_E,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_E);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_E!",L"Error",MB_OK);
	}

	alSourcei( Source_E, AL_BUFFER,      Buffer_E);
	alSourcef( Source_E, AL_PITCH,       1.0);
	alSourcef( Source_E, AL_GAIN,        1.0);
	alSourcefv(Source_E, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_E, AL_POSITION,    SourcePos);
	alSourcei(Source_E, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_E  ////////////////////////////

	/////////////////////////////  key_F  ////////////////////////////
	alGenBuffers(1,&Buffer_F);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_F!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/F.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_F,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_F);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_F!",L"Error",MB_OK);
	}

	alSourcei( Source_F, AL_BUFFER,      Buffer_F);
	alSourcef( Source_F, AL_PITCH,       1.0);
	alSourcef( Source_F, AL_GAIN,        1.0);
	alSourcefv(Source_F, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_F, AL_POSITION,    SourcePos);
	alSourcei(Source_F, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_F  ////////////////////////////
	/////////////////////////////  key_F_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_F_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_F_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/F#.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_F_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_F_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_F_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_F_sharp, AL_BUFFER,      Buffer_F_sharp);
	alSourcef(Source_F_sharp, AL_PITCH,       1.0);
	alSourcef( Source_F_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_F_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_F_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_F_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_F_sharp  ////////////////////////////

	/////////////////////////////  key_G  ////////////////////////////
	alGenBuffers(1,&Buffer_G);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_G!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/G.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_G,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_G);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_G!",L"Error",MB_OK);
	}

	alSourcei( Source_G, AL_BUFFER,      Buffer_G);
	alSourcef( Source_G, AL_PITCH,       1.0);
	alSourcef( Source_G, AL_GAIN,        1.0);
	alSourcefv(Source_G, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_G, AL_POSITION,    SourcePos);
	alSourcei(Source_G, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_G  ////////////////////////////

	/////////////////////////////  key_G_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_G_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_G_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/G#.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_G_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_G_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_G_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_G_sharp, AL_BUFFER,      Buffer_G_sharp);
	alSourcef( Source_G_sharp, AL_PITCH,       1.0);
	alSourcef( Source_G_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_G_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_G_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_G_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_G_sharp  ////////////////////////////

	/////////////////////////////  key_A  ////////////////////////////
	alGenBuffers(1,&Buffer_A);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_A!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/A.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_A,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_A);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_A!",L"Error",MB_OK);
	}

	alSourcei( Source_A, AL_BUFFER,      Buffer_A);
	alSourcef( Source_A, AL_PITCH,       1.0);
	alSourcef( Source_A, AL_GAIN,        1.0);
	alSourcefv(Source_A, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_A, AL_POSITION,    SourcePos);
	alSourcei(Source_A, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_A  ////////////////////////////

	/////////////////////////////  key_A_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_A_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_A_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/A#.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_A_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_A_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_A_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_A_sharp, AL_BUFFER,      Buffer_A_sharp);
	alSourcef( Source_A_sharp, AL_PITCH,       1.0);
	alSourcef( Source_A_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_A_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_A_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_A_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_A_sharp  ////////////////////////////

	/////////////////////////////  key_B  ////////////////////////////
	alGenBuffers(1,&Buffer_B);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_B!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/B.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_B,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_B);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_B!",L"Error",MB_OK);
	}

	alSourcei( Source_B, AL_BUFFER,      Buffer_B);
	alSourcef( Source_B, AL_PITCH,       1.0);
	alSourcef( Source_B, AL_GAIN,        1.0);
	alSourcefv(Source_B, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_B, AL_POSITION,    SourcePos);
	alSourcei(Source_B, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	
	/////////////////////////////  key_B  ////////////////////////////

	/////////////////////////////  key_C1  ////////////////////////////
	alGenBuffers(1,&Buffer_C1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_C1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/C+1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_C1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_C1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_C1!",L"Error",MB_OK);
	}

	alSourcei( Source_C1, AL_BUFFER,      Buffer_C1);
	alSourcef( Source_C1, AL_PITCH,       1.0);
	alSourcef( Source_C1, AL_GAIN,        1.0);
	alSourcefv(Source_C1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_C1, AL_POSITION,    SourcePos);
	alSourcei(Source_C1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
		
	/////////////////////////////  key_C1  ////////////////////////////
	/////////////////////////////////////////////////////////////////
	///////////////////////// MIDDLE 'C' KEYS ///////////////////////
	//////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	///////////////////////// LOWER OCTAVE KEYS ///////////////////////
	//////////////////////////////////////////////////////////////////
	/////////////////////////////  key_C_1  ////////////////////////////

	alGenBuffers(1,&Buffer_C_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_C_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/C-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_C_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_C_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_C_1!",L"Error",MB_OK);
	}

	alSourcei( Source_C_1, AL_BUFFER,      Buffer_C_1);
	alSourcef( Source_C_1, AL_PITCH,       1.0);
	alSourcef( Source_C_1, AL_GAIN,        1.0);
	alSourcefv(Source_C_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_C_1, AL_POSITION,    SourcePos);
	alSourcei(Source_C_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_C_1  ////////////////////////////

	/////////////////////////////  key_C_1_sharp  ////////////////////////////

	alGenBuffers(1,&Buffer_C_1_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_C_1_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/C#-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_C_1_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_C_1_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_C_1_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_C_1_sharp, AL_BUFFER,      Buffer_C_1_sharp);
	alSourcef( Source_C_1_sharp, AL_PITCH,       1.0);
	alSourcef( Source_C_1_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_C_1_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_C_1_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_C_1_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_C_1_sharp  ////////////////////////////

	/////////////////////////////  key_D_1  ////////////////////////////
	alGenBuffers(1,&Buffer_D_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_D_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/D-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_D_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_D_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_D_1!",L"Error",MB_OK);
	}

	alSourcei( Source_D_1, AL_BUFFER,      Buffer_D_1);
	alSourcef( Source_D_1, AL_PITCH,       1.0);
	alSourcef( Source_D_1, AL_GAIN,        1.0);
	alSourcefv(Source_D_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_D_1, AL_POSITION,    SourcePos);
	alSourcei(Source_D_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_D_1  ////////////////////////////

	/////////////////////////////  key_D_1_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_D_1_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_D_1_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/D#-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_D_1_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_D_1_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_D_1_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_D_1_sharp, AL_BUFFER,      Buffer_D_1_sharp);
	alSourcef( Source_D_1_sharp, AL_PITCH,       1.0);
	alSourcef( Source_D_1_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_D_1_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_D_1_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_D_1_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_D_1_sharp  ////////////////////////////

	/////////////////////////////  key_E_1  ////////////////////////////
	alGenBuffers(1,&Buffer_E_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_E_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/E-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_E_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_E_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_E_1!",L"Error",MB_OK);
	}

	alSourcei( Source_E_1, AL_BUFFER,      Buffer_E_1);
	alSourcef( Source_E_1, AL_PITCH,       1.0);
	alSourcef( Source_E_1, AL_GAIN,        1.0);
	alSourcefv(Source_E_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_E_1, AL_POSITION,    SourcePos);
	alSourcei(Source_E_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_E_1  ////////////////////////////

	/////////////////////////////  key_F_1  ////////////////////////////
	alGenBuffers(1,&Buffer_F_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_F_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/F-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_F_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_F_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_F_1!",L"Error",MB_OK);
	}

	alSourcei( Source_F_1, AL_BUFFER,      Buffer_F_1);
	alSourcef( Source_F_1, AL_PITCH,       1.0);
	alSourcef( Source_F_1, AL_GAIN,        1.0);
	alSourcefv(Source_F_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_F_1, AL_POSITION,    SourcePos);
	alSourcei(Source_F_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_F_1  ////////////////////////////
	/////////////////////////////  key_F_1_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_F_1_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_F_1_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/F#-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_F_1_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_F_1_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_F_1_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_F_1_sharp, AL_BUFFER,      Buffer_F_1_sharp);
	alSourcef(Source_F_1_sharp, AL_PITCH,       1.0);
	alSourcef( Source_F_1_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_F_1_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_F_1_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_F_1_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_F_1_sharp  ////////////////////////////

	/////////////////////////////  key_G_1  ////////////////////////////
	alGenBuffers(1,&Buffer_G_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_G_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/G-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_G_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_G_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_G_1!",L"Error",MB_OK);
	}

	alSourcei( Source_G_1, AL_BUFFER,      Buffer_G_1);
	alSourcef( Source_G_1, AL_PITCH,       1.0);
	alSourcef( Source_G_1, AL_GAIN,        1.0);
	alSourcefv(Source_G_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_G_1, AL_POSITION,    SourcePos);
	alSourcei(Source_G_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_G_1  ////////////////////////////

	/////////////////////////////  key_G_1_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_G_1_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_G_1_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/G#-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_G_1_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_G_1_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_G_1_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_G_1_sharp, AL_BUFFER,      Buffer_G_1_sharp);
	alSourcef( Source_G_1_sharp, AL_PITCH,       1.0);
	alSourcef( Source_G_1_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_G_1_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_G_1_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_G_1_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_G_1_sharp  ////////////////////////////

	/////////////////////////////  key_A_1  ////////////////////////////
	alGenBuffers(1,&Buffer_A_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_A_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/A-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_A_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_A_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_A_1!",L"Error",MB_OK);
	}

	alSourcei( Source_A_1, AL_BUFFER,      Buffer_A_1);
	alSourcef( Source_A_1, AL_PITCH,       1.0);
	alSourcef( Source_A_1, AL_GAIN,        1.0);
	alSourcefv(Source_A_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_A_1, AL_POSITION,    SourcePos);
	alSourcei(Source_A_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_A_1  ////////////////////////////

	/////////////////////////////  key_A_1_sharp  ////////////////////////////
	alGenBuffers(1,&Buffer_A_1_sharp);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_A_1_sharp!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/A#-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_A_1_sharp,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_A_1_sharp);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_A_1_sharp!",L"Error",MB_OK);
	}

	alSourcei( Source_A_1_sharp, AL_BUFFER,      Buffer_A_1_sharp);
	alSourcef( Source_A_1_sharp, AL_PITCH,       1.0);
	alSourcef( Source_A_1_sharp, AL_GAIN,        1.0);
	alSourcefv(Source_A_1_sharp, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_A_1_sharp, AL_POSITION,    SourcePos);
	alSourcei(Source_A_1_sharp, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	/////////////////////////////  key_A_1_sharp  ////////////////////////////

	/////////////////////////////  key_B_1  ////////////////////////////
	alGenBuffers(1,&Buffer_B_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_B_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/B-1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_B_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_B_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_B_1!",L"Error",MB_OK);
	}

	alSourcei( Source_B_1, AL_BUFFER,      Buffer_B_1);
	alSourcef( Source_B_1, AL_PITCH,       1.0);
	alSourcef( Source_B_1, AL_GAIN,        1.0);
	alSourcefv(Source_B_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_B_1, AL_POSITION,    SourcePos);
	alSourcei(Source_B, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	
	/////////////////////////////  key_B_1  ////////////////////////////

	/////////////////////////////  key_B_1_1  ////////////////////////////
	alGenBuffers(1,&Buffer_B_1_1);
	if(alGetError() != AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Buffer_B_1_1!",L"Error",MB_OK);
	}

	alutLoadWAVFile("C:/Users/Mib/Music/piano_final_wave/B--1.wav",&format,&data,&size,&freq,&loop);
	alBufferData(Buffer_B_1_1,format,data,size,freq);
	alutUnloadWAV(format,data,size,freq);

	alGenSources(1,&Source_B_1_1);
	if(alGetError == AL_NO_ERROR)
	{
		MessageBox(0,L"Can't create Source_B_1_1!",L"Error",MB_OK);
	}

	alSourcei( Source_B_1_1, AL_BUFFER,      Buffer_B_1_1);
	alSourcef( Source_B_1_1, AL_PITCH,       1.0);
	alSourcef( Source_B_1_1, AL_GAIN,        1.0);
	alSourcefv(Source_B_1_1, AL_VELOCITY,    SourceVel);
	alSourcefv(Source_B_1_1, AL_POSITION,    SourcePos);
	alSourcei(Source_B_1_1, AL_LOOPING, loop);

	if(alGetError == AL_NO_ERROR)
		return AL_TRUE;
	}	
	/////////////////////////////  key_B_1_1  ////////////////////////////
	/////////////////////////////////////////////////////////////////
	///////////////////////// MIDDLE 'C' KEYS ///////////////////////
	//////////////////////////////////////////////////////////////////
	

void SetListenerValues()
{
	alListenerfv(AL_POSITION,    ListenerPos);
	alListenerfv(AL_VELOCITY,    ListenerVel);
	alListenerfv(AL_ORIENTATION, ListenerOri);
}

void KillALData()
{
	////////////////////  MIDDLE 'C' KEYS /////////////////
	alDeleteBuffers(1, &Buffer_C); alDeleteSources(1, &Source_C);
	alDeleteBuffers(1, &Buffer_D); alDeleteSources(1, &Source_D);
	alDeleteBuffers(1, &Buffer_D); alDeleteSources(1, &Source_E);
	alDeleteBuffers(1, &Buffer_F); alDeleteSources(1, &Source_F);
	alDeleteBuffers(1, &Buffer_G); alDeleteSources(1, &Source_G);
	alDeleteBuffers(1, &Buffer_A); alDeleteSources(1, &Source_A);
	alDeleteBuffers(1, &Buffer_B); alDeleteSources(1, &Source_B);
	alDeleteBuffers(1, &Buffer_C1); alDeleteSources(1, &Source_C1);
	alDeleteBuffers(1, &Buffer_C_sharp); alDeleteSources(1, &Source_C_sharp);
	alDeleteBuffers(1, &Buffer_D_sharp); alDeleteSources(1, &Source_D_sharp);
	alDeleteBuffers(1, &Buffer_F_sharp); alDeleteSources(1, &Source_F_sharp);
	alDeleteBuffers(1, &Buffer_G_sharp); alDeleteSources(1, &Source_G_sharp);
	alDeleteBuffers(1, &Buffer_A_sharp); alDeleteSources(1, &Source_A_sharp);
	////////////////////  MIDDLE 'C' KEYS /////////////////

	////////////////////  LOWER OCTAVE KEYS /////////////////
	alDeleteBuffers(1, &Buffer_C_1); alDeleteSources(1, &Source_C_1);
	alDeleteBuffers(1, &Buffer_D_1); alDeleteSources(1, &Source_D_1);
	alDeleteBuffers(1, &Buffer_E_1); alDeleteSources(1, &Source_E_1);
	alDeleteBuffers(1, &Buffer_F_1); alDeleteSources(1, &Source_F_1);
	alDeleteBuffers(1, &Buffer_G_1); alDeleteSources(1, &Source_G_1);
	alDeleteBuffers(1, &Buffer_A_1); alDeleteSources(1, &Source_A_1);
	alDeleteBuffers(1, &Buffer_B_1); alDeleteSources(1, &Source_B_1);
	alDeleteBuffers(1, &Buffer_B_1_1); alDeleteSources(1, &Source_B_1_1);
	alDeleteBuffers(1, &Buffer_C_1_sharp); alDeleteSources(1, &Source_C_1_sharp);
	alDeleteBuffers(1, &Buffer_D_1_sharp); alDeleteSources(1, &Source_D_1_sharp);
	alDeleteBuffers(1, &Buffer_F_1_sharp); alDeleteSources(1, &Source_F_1_sharp);
	alDeleteBuffers(1, &Buffer_G_1_sharp); alDeleteSources(1, &Source_G_1_sharp);
	alDeleteBuffers(1, &Buffer_A_1_sharp); alDeleteSources(1, &Source_A_1_sharp);
	//////////////////// LOWER OCTAVE KEYS /////////////////

	alutExit();
}


void WmCommand(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lp)
	{
			if(lp == (LPARAM)key_C)
			alSourcePlay(Source_C); 
		else if(lp ==  (LPARAM)key_D)
			alSourcePlay(Source_D);
		else if(lp == (LPARAM)key_E)
			alSourcePlay(Source_E);
		else if(lp == (LPARAM)key_F)
			alSourcePlay(Source_F);
		else if(lp == (LPARAM)key_G)
			alSourcePlay(Source_G);
		else if(lp == (LPARAM)key_A)
			alSourcePlay(Source_A);
		else if(lp == (LPARAM)key_B)
			alSourcePlay(Source_B);
		else if(lp == (LPARAM)key_C1)
			alSourcePlay(Source_C1);
		else if(lp == (LPARAM)key_C_sharp)
			alSourcePlay(Source_C_sharp);
		else if(lp == (LPARAM)key_D_sharp)
			alSourcePlay(Source_D_sharp);
		else if(lp == (LPARAM)key_F_sharp)
			alSourcePlay(Source_F_sharp);
		else if(lp == (LPARAM)key_G_sharp)
			alSourcePlay(Source_G_sharp);
		else if(lp == (LPARAM)key_A_sharp)
			alSourcePlay(Source_A_sharp);
		else if(lp == (LPARAM)key_C_1)
			alSourcePlay(Source_C_1); 
		else if(lp ==  (LPARAM)key_D_1)
			alSourcePlay(Source_D_1);
		else if(lp == (LPARAM)key_E_1)
			alSourcePlay(Source_E_1);
		else if(lp == (LPARAM)key_F_1)
			alSourcePlay(Source_F_1);
		else if(lp == (LPARAM)key_G_1)
			alSourcePlay(Source_G_1);
		else if(lp == (LPARAM)key_A_1)
			alSourcePlay(Source_A_1);
		else if(lp == (LPARAM)key_B_1)
			alSourcePlay(Source_B_1);
		else if(lp == (LPARAM)key_B_1_1)
			alSourcePlay(Source_B_1_1);
		else if(lp == (LPARAM)key_C_1_sharp)
			alSourcePlay(Source_C_1_sharp);
		else if(lp == (LPARAM)key_D_1_sharp)
			alSourcePlay(Source_D_1_sharp);
		else if(lp == (LPARAM)key_F_1_sharp)
			alSourcePlay(Source_F_1_sharp);
		else if(lp == (LPARAM)key_G_1_sharp)
			alSourcePlay(Source_G_1_sharp);
		else if(lp == (LPARAM)key_A_1_sharp)
			alSourcePlay(Source_A_1_sharp);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg)
	{
	case WM_DESTROY: PostQuitMessage(0);break;
	case WM_COMMAND: WmCommand(hWnd,msg,wp,lp);break;
	case WM_KEYUP: {
		///////////// LOWER OCTAVE KEYS /////////////
		if(wp == 0x51)					// key 'Q'
			alSourcePlay(Source_B_1_1); // plays LOWEST B
		else if(wp == 0x57 )					// key 'W'			
				alSourcePlay(Source_C_1);   //  plays the note 'C'
		else if(wp == 0x45)					// key 'E'
				alSourcePlay(Source_D_1);    // plays the note 'D'
		else if(wp == 0x52)					// key 'R'
				alSourcePlay(Source_E_1);    // plays the note 'E'
		else if(wp == 0x54)					// key 'T'
				alSourcePlay(Source_F_1);    // plays the note 'F'
		else if(wp == 0x59)					// key 'Y'
				alSourcePlay(Source_G_1);    // plays the note 'G'
		else if(wp == 0x55)					// key 'U'
				alSourcePlay(Source_A_1);    // plays the note 'A'
		else if(wp == 0x49)					// key 'I'
				alSourcePlay(Source_B_1);    // plays the note 'B'
		else if(wp == 0x33)					// key '2'
				alSourcePlay(Source_C_1_sharp);	//plays the note 'C#'
		else if(wp == 0x34)					// key '3'
					alSourcePlay(Source_D_1_sharp);	//plays the note 'D#'
		else if(wp == 0x36)					// key '5'
				alSourcePlay(Source_F_1_sharp);	//plays the note 'F#'
		else if(wp == 0x37)					// key '6'
			alSourcePlay(Source_G_1_sharp);	// plays the note 'G#'
		else if(wp == 0x38)					// key '7'
			alSourcePlay(Source_A_1_sharp);	// plays the note 'A#'
				 ///////////// LOWER OCTAVE KEYS /////////////
	///////////// MIDDLE 'C' KEYS /////////////
		else if(wp == 0x43)					// key 'C'
			alSourcePlay(Source_C); // plays the note 'C'
		else if(wp == 0x56 )					// key 'V'			
				alSourcePlay(Source_D);   //  plays the note 'D'
		else if(wp == 0x42)					// key 'B'
				alSourcePlay(Source_E);    // plays the note 'E'
		else if(wp == 0x4E)					// key 'N'
				alSourcePlay(Source_F);    // plays the note 'F'
		else if(wp == 0x4D)					// key 'M'
				alSourcePlay(Source_G);    // plays the note 'G'
		else if(wp ==   0x3C)	// key ','
				alSourcePlay(Source_A);    // plays the note 'A'
		else if(wp == 0x3E)					// key '.'
				alSourcePlay(Source_B);    // plays the note 'B'
		else if(wp ==  0x3F)					// key '/'
			alSourcePlay(Source_C1);    // plays the note 'C1'
		else if(wp == 0x46)					// key 'F'
				alSourcePlay(Source_C_sharp);	//plays the note 'C#'
		else if(wp == 0x47)					// key 'G'
					alSourcePlay(Source_D_sharp);	//plays the note 'D#'
		else if(wp == 0x4A)					// key 'J'
				alSourcePlay(Source_F_sharp);	//plays the note 'F#'
		else if(wp == 0x4B)					// key 'K'
			alSourcePlay(Source_G_sharp);	// plays the note 'G#'
		else if(wp == 0x4C)					// key 'L'
			alSourcePlay(Source_A_sharp);	// plays the note 'A#'
				 ///////////// LOWER OCTAVE KEYS /////////////
		
		
		
		/*case WM_KEYUP: {
		if(wp == 0x41 )					// key 'A'
				{   //  plays the note 'C'
			hBmp_key_C = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			SendMessage(key_C,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_C);}
				   }*/

					 }}
	return DefWindowProc(hWnd, msg, wp,lp);
}




int _stdcall WinMain(HINSTANCE hi,HINSTANCE pi,LPSTR lpstr,int i)
{
	

	MSG m;

	alutInit(0,0);
	alGetError();
	
	if(LoadALData() != AL_FALSE)
	{
		MessageBox(0,L"Can't load from LoadALData()",L"Error",MB_OK);
	}

	SetListenerValues();
	atexit(KillALData);

	WNDCLASS win;
	//int x;

	//winex.cbSize = sizeof(WNDCLASSEX);
	win.cbClsExtra = 0;
	win.cbWndExtra = 0;
	win.hCursor = LoadCursor(0,IDI_APPLICATION);
	win.hIcon = LoadIcon(0,IDI_APPLICATION);
	win.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	win.lpfnWndProc = WndProc;
	win.lpszClassName = L"win";
	win.lpszMenuName = 0;
	win.hInstance = hi;
	win.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClass(&win))
	{
		MessageBox(0,L"Can not register window!",L"Error!",MB_OK | MB_ICONERROR);
	}
	
	window = CreateWindow(L"win",L"Piano",WS_VISIBLE | WS_SYSMENU,50,50,488,159,0,0,hi,0);
	
	if(!window)
	{
		MessageBox(0,L"Can not create window", L"Error!",MB_OK|MB_ICONERROR);
	}

	

	ShowWindow(window, i );

	
								//////////////////////////////////////////
								///////  MIDDLE C KEYS ////////////////////
								///////////////////////////////////////////
	key_C_sharp = CreateWindow(L"BUTTON",L"C#",WS_CHILD |WS_CLIPCHILDREN|BS_BITMAP  ,255,0,25,75,window,0,hi,0);
				hBmp_key_C_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_C_sharp,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp_key_C_sharp);
				ShowWindow(key_C_sharp,i);

	key_D_sharp = CreateWindow(L"BUTTON",L"D#",WS_CHILD |WS_CLIPCHILDREN|BS_BITMAP  ,285,0,25,75,window,0,hi,0);
				hBmp_key_D_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_D_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_D_sharp);
				ShowWindow(key_D_sharp,i);

	key_F_sharp = CreateWindow(L"BUTTON",L"F#",WS_CHILD |WS_CLIPCHILDREN | BS_BITMAP ,345,0,25,75,window,0,hi,0);
				hBmp_key_F_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_F_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_F_sharp);
				ShowWindow(key_F_sharp,i);

	key_G_sharp = CreateWindow(L"BUTTON",L"G#",WS_CHILD |WS_CLIPCHILDREN | BS_BITMAP ,375,0,25,75,window,0,hi,0);
				hBmp_key_G_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_G_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_G_sharp);
				ShowWindow(key_G_sharp,i);

	key_A_sharp = CreateWindow(L"BUTTON",L"A#",WS_CHILD |WS_CLIPCHILDREN | BS_BITMAP ,405,0,25,75,window,0,hi,0);
				hBmp_key_A_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_A_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_A_sharp);
				ShowWindow(key_A_sharp,i);
	

		key_C = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,240,0,30,130,window,0,hi,0);
				hBmp_key_C = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_C,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_C);
				ShowWindow(key_C,i);

		key_D = CreateWindow(L"BUTTON",L"\nD",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,270,0,30,130,window,0,hi,0);
				hBmp_key_D = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_D,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_D);
				ShowWindow(key_D,i);

		key_E = CreateWindow(L"BUTTON",L"\nE",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,300,0,30,130,window,0,hi,0);
		hBmp_key_E = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_E,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_E);
				ShowWindow(key_E,i);

		key_F = CreateWindow(L"BUTTON",L"\nF",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,330,0,30,130,window,0,hi,0);
		hBmp_key_F = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_F,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_F);
				ShowWindow(key_F,i);

		key_G = CreateWindow(L"BUTTON",L"\nG",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,360,0,30,130,window,0,hi,0);
		hBmp_key_G = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_G,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_G);
				ShowWindow(key_G,i);

		key_A = CreateWindow(L"BUTTON",L"\nA", BS_BITMAP | WS_CHILD | WS_CLIPSIBLINGS,390,0,30,130,window,0,hi,0);
		hBmp_key_A = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_A,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_A);
				ShowWindow(key_A,i);

		key_B = CreateWindow(L"BUTTON",L"\nB",BS_BITMAP | WS_CHILD | WS_CLIPSIBLINGS,420,0,30,130,window,0,hi,0);
		hBmp_key_B = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_B,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_B);
				ShowWindow(key_B,i);


	    key_C1 = CreateWindow(L"BUTTON",L"C",BS_BITMAP | WS_CHILD | WS_CLIPSIBLINGS,450,0,30,130,window,0,hi,0);
		hBmp_key_C1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_C1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_C1);
				ShowWindow(key_C1,i);
					//////////////////////////////////////////
								///////  MIDDLE C KEYS ////////////////////
								///////////////////////////////////////////


						//////////////////////////////////////////
								///////  LOWER OCTAVE KEYS ////////////////////
								///////////////////////////////////////////
	key_C_1_sharp = CreateWindow(L"BUTTON",L"C#",WS_CHILD |WS_CLIPCHILDREN|BS_BITMAP  ,45,0,25,75,window,0,hi,0);
				hBmp_key_C_1_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_C_1_sharp,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp_key_C_1_sharp);
				ShowWindow(key_C_1_sharp,i);

	key_D_1_sharp = CreateWindow(L"BUTTON",L"D#",WS_CHILD |WS_CLIPCHILDREN|BS_BITMAP  ,75,0,25,75,window,0,hi,0);
				hBmp_key_D_1_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_D_1_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_D_1_sharp);
				ShowWindow(key_D_1_sharp,i);

	key_F_1_sharp = CreateWindow(L"BUTTON",L"F#",WS_CHILD |WS_CLIPCHILDREN | BS_BITMAP ,135,0,25,75,window,0,hi,0);
				hBmp_key_F_1_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_F_1_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_F_1_sharp);
				ShowWindow(key_F_1_sharp,i);

	key_G_1_sharp = CreateWindow(L"BUTTON",L"G#",WS_CHILD |WS_CLIPCHILDREN | BS_BITMAP ,165,0,25,75,window,0,hi,0);
				hBmp_key_G_1_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_G_1_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_G_1_sharp);
				ShowWindow(key_G_1_sharp,i);

	key_A_1_sharp = CreateWindow(L"BUTTON",L"A#",WS_CHILD |WS_CLIPCHILDREN | BS_BITMAP ,195,0,25,75,window,0,hi,0);
				hBmp_key_A_1_sharp = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\black_shine.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_A_1_sharp,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_A_1_sharp);
				ShowWindow(key_A_1_sharp,i);


		
		key_C_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,30,0,30,130,window,0,hi,0);
				hBmp_key_C_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_C_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_C_1);
				ShowWindow(key_C_1,i);

		key_D_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,60,0,30,130,window,0,hi,0);
				hBmp_key_D_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_D_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_D_1);
				ShowWindow(key_D_1,i);

		key_E_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,90,0,30,130,window,0,hi,0);
				hBmp_key_E_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_E_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_E_1);
				ShowWindow(key_E_1,i);

		key_F_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,120,0,30,130,window,0,hi,0);
				hBmp_key_F_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_F_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_F_1);
				ShowWindow(key_F_1,i);

		key_G_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,150,0,30,130,window,0,hi,0);
				hBmp_key_G_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_G_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_G_1);
				ShowWindow(key_G_1,i);

		key_A_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,180,0,30,130,window,0,hi,0);
				hBmp_key_A_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_A_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_A_1);
				ShowWindow(key_A_1,i);

		key_B_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,210,0,30,130,window,0,hi,0);
				hBmp_key_B_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_B_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_B_1);
				ShowWindow(key_B_1,i);

		key_B_1_1 = CreateWindow(L"BUTTON",L"\nC",WS_CHILD | WS_CLIPSIBLINGS | BS_BITMAP,0,0,30,130,window,0,hi,0);
				hBmp_key_B_1_1 = (HBITMAP)LoadImage(hi,L"C:\\Users\\Mib\\Pictures\\white.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SendMessage(key_B_1_1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp_key_B_1_1);
				ShowWindow(key_B_1_1,i);

	
							//////////////////////////////////////////
								///////  LOWER OCTAVE KEYS ////////////////////
								///////////////////////////////////////////

		
		

	while(GetMessage(&m,0,0,0))
		DispatchMessage(&m);
}

