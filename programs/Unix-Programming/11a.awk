BEGIN{
printf "Total number of books sold in each category\n"}
{books[$1]+=$2}
END{for(item in books)
{
printf"%s sold=%d\n",item,books[item]
total+=books[item]
}
printf"\nTotal books sold=%d\n",total}
