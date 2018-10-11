## File Placement: 

For example, math problems should go in Math/{Problem Title}/{Your File Name}

Make sure your file is saved in your programming language's file extension (e.g. *.java, *.c, *.py, etc.) 

If a title of a problem already exists and you have another solution, upload your solution within the same subfolder.

If you have used a different language then put it in Math/{Name of Problem}/{Language}/{File Name}. 

Similarly, if the topic is not related to Math, then put it in its closest related folder (e.g. Sorting topics should go under the "Sorting" folder.   


If including new algorithms: 
* Add a README.md in the relative folder of the file placement, discussing the algorithm. 
* Update the table of contents in [README.md](https://github.com/matthewsamuel95/ACM-ICPC-Algorithms/blob/master/README.md)


## Pre-requisites:
Install Git: 
*Are you a first time user and just beginning with Open-Source projects? No problem! Here's [how you can install Git on your computer](https://www.digitalocean.com/community/tutorials/how-to-contribute-to-open-source-getting-started-with-git)*
###### After you are done installing Git on your computer:
1. Fork this repository on Github.
2. Clone it onto your computer by opening terminal and running the command $ git clone https ://github.com/{your username}/ACM-ICPC-Algorithms.git
3. Use the actual name of the repository to change into that directory (eg. *$ cd repository*) and create and switch to a new branch by the following command: $ git checkout -b new-branch
4. After modifying existing files or adding new files to the project, add them locally to your repository using $ git add -A command where A is the file
5. Add a short message about what you contributed for with the git commit command. For eg. $ git commit -m "Fixed documentation typos"
6. Now use the command $ git push --set-upstream origin new-branch to push the changes to the current branch of your forked repository
7. Now you can create a Pull Request with the chosen branch as new-branch
