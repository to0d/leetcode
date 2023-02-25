#!/bin/sh
#####################################################
script_abs=$(readlink -f "$0")
script_dir=$(dirname $script_abs)
workspace=$script_dir

#####################################################
#           main routine
#   
#####################################################

usage()
{
    echo "-t [rs|py|c|cpp] type"
    echo "-l               list"
    echo "-m               make"
    echo "-r               run"
    echo "-c               clean"
}

if [ $# -eq 0 ]; then
    echo "lt error: no args specified."
    usage
    exit 1
fi

lt_type=
lt_action_list=0
lt_action_make=0
lt_action_run=0
lt_action_clean=0
lt_count=0

while getopts 't:lmrch' OPTION
do
    case $OPTION in
    t)  if [ -z "$OPTARG" ]; then
            echo "lt error: no type specified."
            exit 1
        fi    
        lt_type=$OPTARG
        if [ $lt_type != "rs" -a $lt_type != "py" -a $lt_type != "c" -a $lt_type != "cpp" ]; then
            echo "lt error: unknown type "$lt_type
            exit 1
        fi 
        ;;
    l)  lt_action_list=1
        lt_count=`expr $lt_count + 1`
        ;;
    m)  lt_action_make=1
        lt_count=`expr $lt_count + 1`
        ;;
    r)  lt_action_run=1
        lt_count=`expr $lt_count + 1`
        ;;
    c)  lt_action_clean=1
        lt_count=`expr $lt_count + 1`
        ;;
    h)  usage
        exit 0
        ;; 
    \?) echo "lt error: unknown parameter '$OPTION'"
        usage
        exit 1
        ;;
    esac
done

if [ $lt_count == 0 ]; then
    echo "lt error: not action specified"
    exit 1
fi

if [ $lt_action_list == 1 ]; then
    
    test_dir_list=$(find $workspace -type d| grep -v -e "\.$")
    for pt_dir in $test_dir_list
    {    
        
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^LT.*\.${lt_type}$")
        
        for pt_name in $test_sh_list
        {   pt_sh=$pt_dir/$pt_name    
            echo $pt_dir/$pt_name 
        }
    }

fi

if [ $lt_action_make == 1 ]; then

    if [ $lt_type != "c" -a $lt_type != "cpp" ]; then
        echo "lt error: can't make \""$lt_type"\" test" 
        exit 1
    fi 
        
    test_dir_list=$(find $workspace -type d| grep -v -e "\.$")
    for pt_dir in $test_dir_list
    {    
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^LT.*\.${lt_type}$")
        if [ ! "$test_sh_list" = "" ]
        then
            cd $pt_dir
            pwd
            make
        fi
    }

fi


if [ $lt_action_run == 1 ]; then

    out_file=$lt_type.out

    cd $workspace

    if [ -f $out_file ]
    then
        rm $out_file
    fi

    if [ $lt_type == "c" -o $lt_type == "cpp" ]; then
  
        test_dir_list=$(find . -type d | grep -v -e "\.$")
        for pt_dir in $test_dir_list
        {    
            # query test
            test_sh_list=$(ls $pt_dir | grep -e "^LT.*\.${lt_type}$")
            if [ ! "$test_sh_list" = "" ]
            then
                pt_sh=$pt_dir/a.out
                pt_out=$pt_sh".out"        
                printf  "%s: " $pt_dir | tee -a $out_file 
                ./$pt_sh > $pt_out 2>&1
                if [ -f $pt_out ]
                then
                    out=`cat $pt_out | grep -i "output"`
                    echo $out | tee -a $out_file 
                else
                    echo "error, result not found!" | tee -a $out_file 
                fi
            fi
        }
        
    elif [ $lt_type == "rs" ]; then
    
        test_dir_list=$(find . -type d | grep -v -e "\.$")
        for pt_dir in $test_dir_list
        {    
            # query test
            test_sh_list=$(ls $pt_dir | grep -e "^LT.*\.rs$")
            
            for pt_name in $test_sh_list
            {           
                pt_sh=$pt_dir/$pt_name    
                pt_out=$pt_sh".out"        
                printf  "%-10s: " $pt_name | tee -a $out_file
                ./$pt_sh > $pt_out 2>&1        
                if [ -f $pt_out ]
                then
                    out=`cat $pt_out | grep -i "output"`
                    pt=`cat $pt_out | grep -i "time="`
                    echo $out $pt | tee -a $out_file 
                else
                    echo "error, result not found!" | tee -a $out_file 
                fi
            }
        }

    else
    
        test_dir_list=$(find . -type d | grep -v -e "\.$")
        for pt_dir in $test_dir_list
        {    
            # query test
            test_sh_list=$(ls $pt_dir | grep -e "^LT.*\.${lt_type}$")

            for pt_name in $test_sh_list
            {           
                pt_sh=$pt_dir/$pt_name    
                pt_out=$pt_sh".out"        
                printf  "%-10s: " $pt_name | tee -a $out_file 
                ./$pt_sh > $pt_out 2>&1
                if [ -f $pt_out ]
                then
                    out=`cat $pt_out | grep -i "output"`
                    echo $out | tee -a $out_file          
                else
                    echo "error, result not found!" | tee -a $out_file
                fi

            }
        }

    fi 
    
fi

if [ $lt_action_clean == 1 ]; then

    if [ $lt_type != "c" -a $lt_type != "cpp" ]; then
        echo "lt error: can't clean \""$lt_type"\" test" 
        exit 1
    fi 
        
    test_dir_list=$(find $workspace -type d| grep -v -e "\.$")
    for pt_dir in $test_dir_list
    {    
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^LT.*\.${lt_type}$")
        if [ ! "$test_sh_list" = "" ]
        then
            cd $pt_dir
            pwd
            make clean
        fi
    }

fi
