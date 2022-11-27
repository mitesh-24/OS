fileName="MyAddressBook"
opt=1
while [ "$opt" -lt 6 ]
do
	echo  "Choose one of the following :"
	echo "1. Create Address Book "
	echo "2. View address book"
	echo "3. Insert records into address book"
	echo "4. Delete a record"
	echo "5. Modify record"
	echo "6. Exit"
	read opt
	case $opt in

	1)
		if [ -e $fileName ]; then
			rm $fileName
		fi
		cont=1
		echo -e "NAME\tNUMBER\t\tADDRESS\n===============================\n" | cat >> $fileName
		while [ "$cont" -gt 0 ]
		do
			echo -e "\n Enter name : "
			read name
			echo "Enter phone number : "
			read number
			echo "enter address : "
			read address
			echo -e "$name\t$number\t$address\n" | cat >> $fileName
			echo "Press 0 to stop or 1 to continue"
			read cont
		done
		;;

	2)
		cat $fileName
		;;

	3)
		echo "Enter name : "
		read name
		echo "Enter phone number : "
		read number
		echo "Enter address : "
		read address
		echo -e "$name\t$number\t$address\n" | cat >> $fileName
		;;

	4)

		echo -e "Delete record\nEnter name or phone number: "
		read pattern
		temp="temp"
		grep -v $pattern $fileName | cat >> $temp
		rm $fileName
		cat $temp | cat >> $fileName
		rm $temp
		;;

	5)

		echo -e "Modify record\nEnter name or phone number"
		read pattern
		temp="temp"
		grep -v $pattern $fileName | cat >> $temp
		rm $fileName
		cat $temp | cat >> $fileName
		rm $temp
		echo "Enter name : "
                read name
                echo "Enter phone number : "
                read number
                echo "Enter address : "
                read address
                echo -e "$name\t$number\t$address\n" | cat >> $fileName
                ;;

	esac
done
