# SWASH

# Mini tutorial Git #

## What is git? ##
Git is a versioning software aimed at software developtment.
It helps teams to collaborate on code with out the danger
of data loss.

## Git on Linux ##
Git is installed by default on most linux operating systems
but it doesn't come with a grafical user interface.
So it has to be used from the commandline.

## Adding your ssh key ##
To use a private git repository you must add an ssh key to the
repository provider. In our case [gitlab](https://gitlab.com/yopspanjers/t32c).

__DONT FOLLOW THESE STEPS IF YOU ALREADY HAVE AN SSH KEY__

To add an ssh key go to [Profile Settings >> SSH Keys](https://gitlab.com/profile/keys),
click "Add ssh key".

Now open your terminal
To Generate the key:
>`ssh-keygen -t rsa -C "your-email@something.com"`

To show you the generated key
>`cat ~/.ssh/id_rsa.pub`


## Cloning the repo ##
To clone the repo navigate to a folder where you want the repo to be
and type:

> `git clone git@gitlab.com:Ruudjhuu/proftaakT32c.git`

## Pull command ##
Before you start working make sure your local branch is up to date by
doing a pull command.
> `git pull`

## Making Changes ##
When doing changes make sure you and your team mates are not working on the same class
to avoid merge changes.

## Commiting ##
After you make a change you must commit your change to your local branch.
You can do this with the commit command
> `git commit . -m "made changes"`

This command commit all the local changes (.), with the commit message "made changes".
Now your local branch differs from the remote branch (on gitlab), to sync these use
> git push

 And a good git rule is: __Commit early and commit often.__
