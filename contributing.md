# How to do simple pull requests in GitHub

A [pull request](https://help.github.com/articles/about-pull-requests/) is a request to merge your work on a codebase or repository into another's master repository.

It is a mechanism by which users can contribute to Open Source projects even if they're not part of any 'official'
development team.

That's the benefit of open source software - anyone can contribute if they take the time to understand and follow the right procedures!

### What are we going to do?

The Open Preservation Foundation maintains a format-corpus. For those starting out with GitHub this represents one of
the lowest barriers for working with GitHub and Pull Requests.

### Assumptions

Git is configured on your system with your user name, a default text editor and you can connect to GitHub.

## Generic Pull Request, e.g. code update/fix

### Steps that we're going to follow

1. [Fork](https://help.github.com/articles/fork-a-repo/) the [repository](https://github.com/openpreserve/format-corpus) by clicking the 'Fork' icon in the top-right corner of GitHub
2. Clone the repository in the command line on your PC:

   **`$ git clone https://github.com/openpreserve/format-corpus`**

3. Navigate to the cloned repository in the OS' file manager GUI or on the command line, e.g.

   **`$ cd format-corpus`**

4. Create a new branch to make a change on

   **`git checkout -b new-branch`**

5. Edit the file/files that are needed for the fix/update. A simple rule of thumb is to make sure the edit is a discrete bug/piece of functionality. If it extends beyond this consider alternative branches and commits.

6. Commit the files to the repository. Commit-ing tells the repository something has been done with the files, in this case, this is just the initial commit so we just say as much.

   **`$ git commit -a`**

7. Your configured text editor will appear. Add your commit message (short commit messages are considered to be better):

   **`[bugfix] Corrected behavior of application given certain parameters.`**

8. Push your changes to your repository (authentication details will appear as you do this).

   **`$ git push`**

9. Head back to your forked GitHub repository.
10. Click the Pull Request tab and click New Pull Request
11. A screen will appear allowing us to review the changes we want to see adopted. We may need to select the link 'compare across forks', and from there our fork, and specific branch for the pull request.
12. Click 'Create Pull Request' and write a description for what's in it.
13. Submit, and wait for the original repository's owner to review the request and merge.
14. Pull request complete.

## Creating a New Folder, e.g. for files in Open Preservation Foundation Format Corpus

### Steps that we're going to follow

1. [Fork](https://help.github.com/articles/fork-a-repo/) the [repository](https://github.com/openpreserve/format-corpus) by clicking the 'Fork' icon in the top-right corner of GitHub
2. Clone the repository in the command line on your PC:

   **`$ git clone https://github.com/openpreserve/format-corpus`**

3. Navigate to the cloned repository in the OS' file manager GUI or on the command line, e.g.

   **`$ cd format-corpus`**

4. Create a new directory in your cloned repository in the OS' file manager GUI or on the command line, e.g.

   **`$ mkdir <new-dir>`**

5. Navigate to your new directory and add a file named README.md , md stands for [markdown text ](https://en.wikipedia.org/wiki/Markdown). We will document the purpose of the files we're including in the repository here, this may include author and licensing conditions as well.
6. Copy into this directory the files and folders that you're adding to the format-corpus

7. Add the new folder to the repository. Add-ing tells the repository that these are files to be tracked.

   **`$ git add <new-dir>`**

8. Commit the files to the repository. Commit-ing tells the repository something has been done with the files, in this case, this is just the initial commit so we just say as much.

   **`$ git commit -a`**

9. Your configured text editor will appear. Add your commit message (short commit messages are considered to be better):

   **`[initial] New files added to the format-corpus for testing preservation workflows.`**

10. Push your changes to your repository (authentication details will appear as you do this).

    **`$ git push`**

11. Head back to your forked GitHub repository.
12. Click the Pull Request tab and click New Pull Request
13. A screen will appear allowing us to review the changes we want to see adopted. We may need to select the link 'compare across forks', and from there our fork, and specific branch for the pull request.
14. Click 'Create Pull Request' and write a description for what's in it.
15. Submit, and wait for the original repository's owner to review the request and merge.
16. Pull request complete.

## Tips and Tricks

- The most important thing to consider with a pull-request (well, it took me some time!) is that they work best on a branch-by-branch basis. So make each discrete change on a separate branch - this means a pull-request will not be polluted by subsequent updates and additions to your code. This makes it a) easier for the code maintainer to select pull-requests to work on. And b) easier for you to continue your work on a 'working' branch. **Best of both worlds!**

#### Endnotes

- GitHub Documentation on Pull Requests: https://help.github.com/articles/creating-a-pull-request/
- Yangsu, A visual guide to Pull Requests: https://yangsu.github.io/pull-request-tutorial/
- OSS Watch, What is a Pull Request: http://oss-watch.ac.uk/resources/pullrequest
