**Project : Compression** 

The program uses the LZW compression algorithm (My modified version) to compress a file into a single file with
".jay" extension. <br>
The program can also compress a folder to a "single" folder with ".jay" extension. <br>
I have used my modified version of LZW algorithm for this project. <br>
The algorithm reads characters from the file and writes them to the dictionary. <br>
The dictionary stores a character sequence which is not in the dictionary entry. <br>
<br>
The program takes a single file for compression and compresses it into a '.jay' format file.(With same name) <br>
Example: <br>
      
    $ ./project -c example 
    >> example.jay will be created. 
The program also takes folders to compress as: <br>
Example: <br>

    $ ./project -dc FOLDER 
    >> FOLDER.jay will be created in the same directory as that of FOLDER.
<br>
Check "./project --help" for more information. <br>
<br>
For decompression or extraction, the program takes a single file or a single folder. The file or folder should have a '.jay' extension. <br>
The outputed file will have the same name without the '.jay' extension. <br>
Example: <br>

    $ ./project -x example.jay 
    >> example will be created. 
<br>
The program will also extract a ".jay" extension folder. <br>
Example: <br>
    
    $ ./project -dx FOLDER.jay 
    >>FOLDER will be created in the same directory of FOLDER.jay 
<br>
Limitations : <br>
The program takes some time to compress very large files. <br>
Although extracting takes less than a second. <br>
Also there is a slight problem with .pdf, .mp3  and some .jpg formats.	A "single" unknown character may occur while decompressing text file. <br>
All other formats work perfectly. <br>
