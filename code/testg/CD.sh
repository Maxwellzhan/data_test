#!/bin/bash
#some imformation

#set some global variation

menu_choice=""
current_cd=""
title_file="title.cdb"
tracks_file="tracks.cdb"
temp_file=/tmp/cdb.$$
trap 'rm -f $temp_file' 'EXIT
#simple tool functions

get_return() {
	echo "Press return \c"
	read x
	return 0
 }

get_confirm() {
	echo "Are you sure? \c"
	while true
	do
		read x
		case "x" in
			y | yes | Y | Yes | YES
				return 0;;
			n | no | N | No | NO
				echo 
				echo "Cancelled"
				return 1;;
			*) echo "Please enter yes or no";;
		esac
	done
 }

#main menu set

set_menu_choice() {
	clear
	echo "Options : -"
	echo
	echo "		a) Add new CD"
	echo "		f) Find CD"
	echo "		c) Count the CDs and tracks in catalog"
	if [ "$cdcatnum" != "" ]; then
		echo "		l) List tracks on $cdtitle"
		echo "		r) Remove $cdtitle"
		echo "		u) Update track information for $cdtitle"
	fi
	echo "		q) Quit"
	echo
	echo "Please enter choise then press return \c"
	read menu_choise
	return
}

#add new CD track

insert_title() {
	echo $* >> $title_file
	return
}

insert_track() {
	echo $* >> $tracks_file
	return
}

add_record_tracks() {
	echo "Enter track information for this CD"
	echo "When no more track enter q"
	cdtrack=1
	cdttitle=""
	while [ "$cdttitle" != "q" ]
	do
		echo "Track $cdtrack, track title? \c"
		read tmp
		cdttitle=${tmp%%,*}
		if [ "$tmp" != "$cdttitle" ]; then
			echo "Sorry, no commas allowed"
			continue
		fi
		if [ -n "$cdttitle" ]; then
			if [ "$cdttitle" !="q" ];then
				insert_track $cdcatnum,$cdtrack,$cdttitle
			fi
		else
			cdtrack=$((cdtrack-1))
		fi
	cdtrack=$((cdtrack+1))
done
}

#add new CD information

add_records() {
	
	#gain initial imformation
	echo "Enter catalog name \c"
	read tmp
	cdcatnum=${tmp%%,*}

	echo "Enter title \c"
	read tmp
	cdtitle=${tmp%%,*}

	echo -e "Enter type \c"
	read tmp
	cdtype=${tmp%%,*}
	
	echo "Enter artist/composer \c"
	read tmp
	cdac=${tmp%%,*}

	#check they want
	echo About to add new entry
	echo "$cdcatnum,$cdtitle,$cdtype,$cdac"

	#appent to File
	if get_confirm ; then
		insert_title $cdcatnum,$cdtitle,$cdtype,$cdac
		add_record_tracks
	else
		remove_records
	fi
	return
}

#Find some information
find_cd() {
	if [ "$1" = "n" ]; then
		asklist=n
	else
		asklist=y
	fi
	cdcatnum=""
	echo "Enter a string to search for in CD titles \c"
	read searchstr
	if [ "$searchstr" = "" ]; then
		return 0
	fi
	
	grep "$searchstr" $title_file > $temp_file

	set $(wc -l $temp_file)
	linesfound=$1

	case "$linesfound" in
		0)	echo "Sorry,nothing found"
			get_return
			return 0
			;;
		1)	;;
		2)	echo "Sorry,not unipue."
			echo "Found the following"
			cat $temp_file
			get_return
			return 0
	esac
	
	IFS=","
	read cdcatnum cdtitle cdtype cdac < $temp_file
	IFS=" "

	if [ -z "$cdcatnum" ]; then
		echo "Sorry,could not extract catalog field from $temp_file"
		get_return
		return 0
	fi

	echo
	echo Catalog number: $cdcatnum
	echo Title: $cdtitle
	echo Type: $cdtype
	echo Artist/Composer: $cdac
	echo
	get_return

	if [ "$asklist"="y" ]; then
		echo -e "View tracks for this CD? \c"
		read x
		if [ "$x"="y" ]; then
			echo
			list_tracks
			echo
		fi
	fi
	return 1
} 

#count numbers of CD
count_cds() {
	set $(wc -l $title_file)
	num_titles=$1
	set $(wc -l $tracks_file)
	num_tracks=$1
	echo found $num_titles CDs, with a total of $num_tracks tracks
	get_return
	return
}

#remove one
remov_records() {
	if [ -z "$cdcatnum" ]; then
		echo You must select a CD first
		find_cd n
	fi
	if [ -n "$cdcatnum" ]; then
		echo "You are about to delete $cdtitle"
		get_confirm && {
			grep -v "^${cdcatnum}," $title_file > $temp_file
			mv $temp_file $title_file
			grep -v "^${cdcatnum}," $tracks_file > $temp_file
			mv $temp_file $tracks_file
			cdcatnum=""
			echo Entry to remove
		}
		get_return
	fi
	return 
}

#list your require
list_tracks() {
	if [ "$cdcatnum" = "" ]; then
		echo no CD selected yet
		return
	else
		grep "^{cdcatnum}," $track_file > $temp_file
		num_tracks=$(wc -l $temp_file)
		if [ "num_tracks" = "0" ]; then
			echo "no tracks found for $cdtitle"
		else {
			echo
			echo "$cdtitle: -"
			echo
			cut -f 2- -d, $temp_file
			echo		
		}
		fi
	fi
	get_return
	return
}

#main code
rm -f $temp_file
if [ ! -f $title_file ]; then
	touch $title_file
fi

clear
echo
echo
echo "Mini CD manager"
sleep 1

quit=n
while [ "$quit" != "y" ];
do
	set_menu_choise
	case "$menu_choise" in
		a) add_records;;
		r) remove_records;;
		f) find_cd y;;
		u) update_cd;;
		c) cout_cds;;
		l) list_tracks;;
		b)
			echo
			more $title_file
			echo
			get_return;;
		q | Q ) quit="y";;
		*) echo "Sorry,choise not recognise";;
	esac
done

rm -f $temp_title
echo Finished
exit 0
