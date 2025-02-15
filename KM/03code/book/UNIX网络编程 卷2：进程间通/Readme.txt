CAVEATS
=======

1. Please do NOT send me email with your "make" output, asking me what to
   do to get the source code working on your system.  You would not believe
   the volume of email that I get like this, and I just don't have the
   time to even respond to these any more.  My suggestion is to get someone
   locally to help (at work or at school) or to ask on some vendor-specific
   Usenet newsgroup.

   My publisher graciously allows all the code to be made available (to save
   you from having to type it in), but the code is provided "as is" with no
   support implied.

2. The code in the book uses features that are not widespread during 1998
   (e.g., Posix IPC, a *working* pthreads library, Posix realtime signals,
   etc.).  The *only* Unix systems that I found that supported everything
   that I wanted to cover in the book were Solaris 2.6 and Digital Unix
   4.0B (excluding doors, which I know are Solaris-only, and Posix read-write
   locks, which only AIX supports).  If you are bringing up the source code
   on some other system *expect* to find features described in the book
   that your system does not support.

   I have brought up pieces of the code (mainly the library and a few
   test programs) on BSD/OS 3.1, RedHat Linux 5.1, and AIX 4.3.1, but I
   do not have the time and resources to try and port the code to all
   other possible Unix variants (and all the various Linux variants with
   different kernels and libraries).  I think the code is quite portable
   but it will require some effort to port the code to other Unix systems.

QUICK AND DIRTY
===============

Execute the following from the src/ directory:

    ./configure    # try to figure out all implementation differences

    cd lib         # build the basic library that all programs need
    make           # use "gmake" everywhere on BSD/OS systems

    cd ../pipe     # build and test a simple program
    make pipeconf
    ./pipeconf /tmp

If all that works, you're all set to start compiling individual programs.

Notice that all the source code assumes tabs every 4 columns, not 8.

MORE DETAILS
============

5.  If you need to make any changes to the "unpipc.h" header, notice that
    it is a hard link in each directory, so you only need to change it once.

6.  If configure runs OK but you encounter problems building the library,
    the easiest fix is to change either of the files "src/Make.defines" or
    "src/config.h" accordingly.  These two files are generated by the
    configure script and are used by all the programs.  You may need to
    change the CFLAGS variable in "Make.defines" or comment out certain
    features in "config.h".

7.  Go into the "lib/" directory and type "make".  This builds the library
    "libunpipc.a" that is required by almost all of the programs.  There may
    be compiler warnings (see NOTES below).  This step is where you'll find
    all of your system's dependencies, and you must just update your cf/
    files from step 1, rerun "config" and do this step again.

    Expect some warnings from your C compiler (I always run gcc with -Wall)
    because all systems have some broken header files and some automatically
    generated programs (e.g., Sun RPC) generate unused variables and the
    like.

8.  Once the library is made from step 7, you can then go into any
    of the source code directories and make whatever program you are
    interested in.  Note that the horizontal rules at the beginning and
    end of each program listing in the book contain the directory name and
    filename.

    BEWARE: Not all programs in each directory will compile on all systems
    (e.g., the directories pxmsg/, pxsem/, and pxshm require support of
    the corresponding Posix realtime functions; the directory src/doors/
    will only run under Solaris, etc.)  Also, not all files in each
    directory are included in the book.  Beware of any files with "test"
    in the filename: they are probably a quick test program that I wrote
    to check something, and may or may not work.

NOTES
-----

- Many systems do not have correct function prototypes for some of the
  functions, and this can cause many warnings during compilation.
  For example, the Solaris 2.6 <sys/mman.h> header does not define the
  function prototype for shm_open() and shm_unlink() for the right set
  of compiler flags.  Solaris 2.6 also defines the old "char *" argument
  for shmdt() by default, instead of the newer "const void *" argument.

- SunOS 4.1.x: If you are using Sun's acc compiler, you need to run
  the configure program as

        CC=acc CFLAGS=-w CPPFLAGS=-w ./configure

  (This note is from my experiences with SunOS 4.1.3 with the source code
  from Volume 1.  I have not tried to compile the Volume 2 source code
  under this OS.)

