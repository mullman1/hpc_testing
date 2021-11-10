#!/bin/sh -x
ssh-add -l
for HOST in karhold riverrun harrenhal pinkmaiden lannisport silverhill crakehall faircastle ashford bitterbridge eastwatch # greyguard excluded
do
    # ssh $HOST hostname
    rsync -aH -zz -v $HOME/src/ $HOST:$HOME/src/
done
