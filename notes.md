extract text. apply recursive chunking with overlap, return chunks and upload to postgres.


Table 1: documents
id	filename
1	report.pdf
2	notes.txt


Table 2: chunks
id	document_id	chunk_index	content 
1	1	0	"This is an example..."
2	1	1	"This is another example..."
3	1	2	"This is a third example..."
4	2	0	"Shopping list..."