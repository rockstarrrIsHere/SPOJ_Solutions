#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Model: Seed Template, Template: Other template hits

struct atom
{
	char type[10];			  //Type of the structure, i.e. ATOM (0th column)
	int an; 			  //Atom Number treated as Index (1nd column)
	char mol[10]; 			  //Molecule     		 (2rd column)
	char amino[10];			   //Amino Acid 		 (3th column)		
	char chainid[2]; 		   //Chain ID  			 (4th column)		
	int pos;                           //Position   		 (5th column)		
	float xc;                          //X Coordinate		 (6th column)		
	float yc;                          //Y Coordinate		 (7th column)		
	float zc;                          //Z Coordinate		 (8th column)	
	float occ;	                   //Occupancy	  		 (9th Column)			
	float temp;	                   //Temperature Identifier	 (10th Column)
	char element[2];                   //Element Symbol		 (11th Column)
};


struct atom *matm,*tatm;
typedef struct atom Atom;

void copyField(char *to, const char *from, int start, int end)
{
	int length=end - start + 1;
	strncpy(to, &from[start-1],length);
	to[length]='\0';
}

//modelPDB to array format 2. 
Atom * mpdbToArray2(char * filename)		//Template PDB file to convert into arrays
{
    char line[1000], temp[15][15];
    char *p, *endptr;
    int i,j,k,flag;

    FILE * pdbfile = fopen(filename, "r");
    while(pdbfile == NULL)			// Checking if file loaded successfully or not
    {
	printf("\n\nERROR: %s not found\n\n", filename);
	return NULL;
    }

    i = 0;

    while(fgets(line, sizeof(line), pdbfile))    // Loop to find the number of atoms
    {
	if (line[0]== 'A' && line[1] == 'T' && line[2] == 'O' && line[3] == 'M')
	{
		i++;
	}
    }

    Atom *arr;
    arr = malloc(i*(sizeof(Atom)));


    fseek(pdbfile, 0, SEEK_SET);		// Seeking the cursor back to start of file
    k = 0;
    while(fgets(line, sizeof(line), pdbfile))
    {
        if (line[0]== 'A' && line[1] == 'T' && line[2] == 'O' && line[3] == 'M')
	{
		p = line;
		i = 0;
		j = 0;
		flag = 0;
		
		strcpy(arr[k].type,"ATOM");

		copyField(temp[1],line,7,11);
		arr[k].an = strtol(temp[1],NULL,10);

		copyField(temp[2],line,13,16);
		strcpy(arr[k].mol,temp[2]);

		copyField(temp[3],line,18,20);
		strcpy(arr[k].amino,temp[3]);

		copyField(temp[4],line,22,22);
		strcpy(arr[k].chainid,temp[4]);		

		copyField(temp[5],line,23,26);
		arr[k].pos=strtol(temp[5],NULL,10);	

		copyField(temp[6],line,31,38);
		arr[k].xc=strtof(temp[6],&endptr);

		copyField(temp[7],line,39,46);
		arr[k].yc=strtof(temp[7],&endptr);

		copyField(temp[8],line,47,54);
		arr[k].zc=strtof(temp[8],&endptr);

		copyField(temp[9],line,55,60);
		arr[k].occ=strtof(temp[9],&endptr);

		copyField(temp[10],line,61,66);
		arr[k].temp=strtof(temp[10],&endptr);

		copyField(temp[11],line,77,78);
		strcpy(arr[k].element,temp[11]);
		//printf("\n%4d %5s %5s %5s %4d %7.3f %7.3f %7.3f %7.3f  %7.3f ",arr[k].an, arr[k].mol, arr[k].amino, arr[k].chainid, arr[k].pos, arr[k].xc, arr[k].yc, arr[k].zc,arr[k].occ,arr[k].temp,arr[k].element);
		k++;
	}
    }
    return arr;
}



/*
void displayArray(Atom * arr)	// To display all the atoms in an array of type Atom (for debugging purposes)
{
	if(arr == NULL)return;
	int i = 0;
	for(i = 0;strcmp(arr[i].type, "ATOM") == 0;i++)
	{
	printf("%d\t%s\t%s\t%s\t%d\t%f\t%f\t%f %s", arr[i].an, arr[i].mol, arr[i].amino, arr[i].chainid, arr[i].pos, arr[i].xc, arr[i].yc, arr[i].zc, "\n\n");
	}
}
*/





int j=0;
int arraylength(Atom * arr)	// To count number of atoms in an array of type Atom (for debugging purposes)
{
	if(arr == NULL) return 0;
	int i = 0;
	int j = 0;
	for(i = 0;strcmp(arr[i].type, "ATOM") == 0;i++)
	{
		j++;
	}
	return j;
}





int main(int argc, char *argv[])
{
	printf("\nThis script's information can be best viewed in 1024x768 Resolution Desktop Window");
	printf("\nIf you have not compiled code as ./a.out alignment_filename.ali, Re-Execute..");
	printf("\nAlso Make sure that, only the amino acid residues are there in the Alignment\n");
	if (argc != 2 )		
	{
		printf("\nError: Please Enter the syntax properly stating the alignment filename after ./a.out (binary)\n");
		return 0;
	}
	char * MSA_alignmentfilename=argv[1];
	if (strstr(MSA_alignmentfilename,".ali")==NULL)
	{	
		printf("\nAlignment filename is not entered. Recheck your Input file\n");
		return 0;
	}
	//sleep(5);	Remove this comment later
	char MSA_line[5000], MSA_temp[15];
	char *p, *endptr;
	int i,j,k,flag;

	FILE * MSA_alifile = fopen(argv[1], "r");
	while(MSA_alifile == NULL)			// Checking if file loaded successfully or not
	   {
		printf("\n\nERROR: %s not found\n\n", MSA_alignmentfilename);
		return 0;
	    }

	fseek(MSA_alifile, 0, SEEK_SET);		// Seeking the cursor back to start of file
	k = 0;int count=0;

	int MSA_tempcount=0;
	fseek(MSA_alifile, 0, SEEK_SET);		// Seeking the cursor back to start of file
	i=0;
	while((fgets(MSA_line,sizeof(MSA_line),MSA_alifile)))
	{
		if((MSA_line[5]=='>') && (MSA_line[0]!='\n') && (MSA_line[1]!='\n') && (MSA_line[2]!='\n') && (MSA_line[0]!='\0') && (MSA_line[1]!='\0'))
		{
			//printf("\nLine0 is %c",MSA_line[0]);
			i++;
		}
		else
		{
		MSA_line[5]='\0';
		MSA_line[0]='\0';
		}
	}	
	MSA_tempcount=i;
	printf("\n%d templates are there in the alignment file",MSA_tempcount);




	char MSA_tempnames[MSA_tempcount][6];char MSA_swap[6];
	fseek(MSA_alifile, 0, SEEK_SET);		// Seeking the cursor back to start of file
	i=0;
	while(fgets(MSA_line,sizeof(MSA_line),MSA_alifile) && (i<MSA_tempcount))
	{
		if((MSA_line[5]=='>') && (MSA_line[0]!='\0'))
		{
			MSA_swap[0]=MSA_line[0];
			//printf("\nSwap0 for %d template=%c",i,MSA_swap[0]);
			MSA_swap[1]=MSA_line[1];
			//printf("\nSwap0 for %d template=%c",i,MSA_swap[1]);
			MSA_swap[2]=MSA_line[2];
			//printf("\nSwap0 for %d template=%c",i,MSA_swap[2]);
			MSA_swap[3]=MSA_line[3];
			//printf("\nSwap0 for %d template=%c",i,MSA_swap[3]);
			MSA_swap[4]=MSA_line[4];
			//printf("\nSwap0 for %d template=%c",i,MSA_swap[4]);
			MSA_swap[5]='\0';
			MSA_line[5] = '\0';
			strcpy(MSA_tempnames[i],MSA_swap);
			i++;
		}
	}
	//for(i=0;i<MSA_tempcount;i++)
	//printf("\nTEMPLATE %2d IS:%s",(i+1),MSA_tempnames[i]);
	//TARGETLENGTH IS targetarraylength in targetarray array of characters and template names are stored in tempnames[i] with maximum template number as tempcount, template sequences in tempseqarr[z][j], templatelen[z]



	fseek(MSA_alifile, 0, SEEK_SET);
	int z=0;
	char MSA_tempseqarr[MSA_tempcount][5000];int MSA_templatelen[MSA_tempcount];
	for(z=0;z<MSA_tempcount;z++)
	{
		fseek(MSA_alifile, 0, SEEK_SET);
		MSA_swap[0]=MSA_tempnames[z][0];
		MSA_swap[1]=MSA_tempnames[z][1];
		MSA_swap[2]=MSA_tempnames[z][2];
		MSA_swap[3]=MSA_tempnames[z][3];
		MSA_swap[4]=MSA_tempnames[z][4];
		while(fgets(MSA_line,sizeof(MSA_line),MSA_alifile))
		{
		     if ((MSA_line[0]==MSA_swap[0]) && (MSA_line[1]==MSA_swap[1]) && (MSA_line[2]==MSA_swap[2]) && 
			 (MSA_line[3]==MSA_swap[3]) && (MSA_line[4]==MSA_swap[4]) && (MSA_line[5]=='>'))
			{
				count=0;
				p = MSA_line;
				i = 0;
				j = 0;
				flag = 0;
				for(;*p != '*';p++)	// Creating string array "temp" with all attributes
							// of 'k'th atom as  elements
				{
					if(*p != '*')
					{
						MSA_temp[i]= *p;
						flag = 1;
						MSA_tempseqarr[z][j]= *p;
						count++;
						j++;
						MSA_temp[i]='\0';
					}
					MSA_templatelen[z]=count-6;
				}
			}
		}
		//printf("\nTemplate Sequence has length %d",MSA_templatelen[z]);
	}




	char MSA_target[5000];int MSA_targetlen;
	fseek(MSA_alifile, 0, SEEK_SET);
	int k1=0;int k2=0;
	
	while(fgets(MSA_line,sizeof(MSA_line),MSA_alifile))
	{
	     if ((toupper(MSA_line[0])=='T') && (toupper(MSA_line[1])=='A') && (toupper(MSA_line[2])=='R') && 
	 (toupper(MSA_line[3])=='G') && (toupper(MSA_line[4])=='E') && (toupper(MSA_line[5])=='T') && (MSA_line[6]=='>'))
		{
			count=0;
			p = MSA_line;
			i = 0;
			j = 0;
			flag = 0;
			for(;*p != '*';p++)	// Creating string array "temp" with all attributes
						// of 'k'th atom as  elements
			{
				if(*p != '*')
				{
					MSA_temp[i]= *p;
					flag = 1;
					MSA_target[j]= *p;
					count++;
					j++;
					MSA_temp[i]='\0';
				}
				MSA_targetlen=count-7;
		
			}
		//printf("\nTarget Sequence has length %d",MSA_targetlen);
		k1++;
		}
	}	
	

	char MSA_templatearray[MSA_tempcount][5000];
	for(i=0;i<MSA_tempcount;i++)
	{
	//printf("\nTEMPLATE %2d IS: %s AND HAS %2d AMINO ACIDS WITH THE SEQUENCE:",(i+1),MSA_tempnames[i],MSA_templatelen[i]);
		for(j=6,k=0;	j<(MSA_templatelen[i] + 6),k<MSA_templatelen[i];	j++,k++)	
		{	
			MSA_templatearray[i][k]=MSA_tempseqarr[i][j];	
			//printf("%c",MSA_templatearray[i][k]);
	
		}
		MSA_templatearray[i][MSA_templatelen[i]]='\0';
		//printf("\n--------%s:%s",MSA_tempnames[i],MSA_templatearray[i]);
	}	
	

	//Copying only the target actual sequences without string TARGET> into different array targetarray[templatelen[0]]

	char MSA_targetarray[5000];
	for(i=0;i<MSA_tempcount;i++)
	{
		//printf("\nTARGET %2d HAS %2d AMINO ACIDS WITH THE SEQUENCE:",(i+1),MSA_targetlen);
		for(j=7,k=0;	j<MSA_targetlen+7,k<MSA_targetlen;	k++,j++)
		{	
			MSA_targetarray[k]=MSA_target[j];	
			//printf("%c",MSA_targetarray[k]);
		}
		MSA_targetarray[MSA_targetlen]='\0';
		//printf("\n--------%s Template:%s",MSA_tempnames[i],MSA_targetarray);
	}	
	
	//printf("\n\n\n============================================================================================");
	//for(i=0;i<MSA_tempcount;i++)
	//printf("\nTEMPLATE:%s HAS LENGTH %d WITH SEQUENCE: %s",MSA_tempnames[i],MSA_templatelen[i],MSA_templatearray[i]);	
	//printf("\n");
	//printf("\n    AND TARGET HAS LENGTH %d WITH SEQUENCE: %s",MSA_targetlen,MSA_targetarray);
	//printf("\n");
	










	//////////////////SEQUENCE COMPARISON BASED ANALYSIS STARTS////////////////////////////////////////////
	//UNGAPPED START BASED TEMPLATE SEQUENCE LENGTH STARTING LENGTH
	int MSA_igcount=0;int MSA_igstart_template[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0,k=0;	j<MSA_targetlen,k<MSA_targetlen;	k++,j++)
		MSA_igcount=0;j=0;
		while((j<MSA_templatelen[i]) && (MSA_templatearray[i][j]=='-'))
		{
			MSA_igcount++;
			j++;
		}
		j=0;
		MSA_igstart_template[i]=MSA_igcount;
	}	
	//for(i=0;i<MSA_tempcount;i++)
	//printf("\n--------------------------Template %s has ungapped start at:%d",MSA_tempnames[i], 				MSA_igstart_template[i]);

	//UNGAPPED START BASED TEMPLATE SEQUENCE ENDING LENGTH
	int MSA_egcount=0;int MSA_egstart_template[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		MSA_egcount=0;j=MSA_templatelen[i]-1;
		while(MSA_templatearray[i][j]=='-')
		{
			MSA_egcount++;
			j--;
		}
		j=0;
		MSA_egstart_template[i]=MSA_templatelen[i]-MSA_egcount;
	}	
	

	//Checking if the MSA_templatelength for every template is the same as the considered MSA_target sequnce length
	for(i=0;i<MSA_tempcount;i++)
	{
		if(MSA_templatelen[i]!=MSA_targetlen)
		printf("\n\t\tTEMPLATE SEQUENCE:%s LENGTH IS NOT MATCHING THE TARGET SEQUENCE LENGTH. RECHECK IT....",
		MSA_tempnames[i]);
	}




	//for(i=0;i<MSA_tempcount;i++)
	//printf("\n--------------------------Template %s with length %d,%d has ungapped end at:%d",MSA_tempnames[i],   	MSA_templatelen[i], MSA_targetlen,MSA_egstart_template[i]);


	//UNGAPPED START BASED TARGET SEQUENCE LENGTH STARTING LENGTH
	MSA_igcount=0;int MSA_igstart_target;j=0;
	while((j<MSA_targetlen) && (MSA_targetarray[j]=='-'))
	{
		MSA_igcount++;
		j++;
	}
	MSA_igstart_target=MSA_igcount;
	//printf("\n--------------------------Target has ungapped start at:%d",MSA_igstart_target);
	
	//UNGAPPED START BASED TARGET SEQUENCE ENDING LENGTH
	int MSA_egstart_target;MSA_egcount=0;j=MSA_targetlen-1;
	//while(MSA_templatearray[i][j]=='-')		Initially checked the same end gaps on both start and end in each 	target
	while(MSA_targetarray[j]=='-')
	{
		MSA_egcount++;
		j--;
	}
	MSA_egstart_target=MSA_targetlen - MSA_egcount;
	//printf("\n--------------------------Target with length %d has ungapped end at:%d", 					MSA_targetlen,MSA_egstart_target);

	//printf("\n%d,%d",MSA_targetlen,MSA_templatelen[0]);
	printf("\n_____________________________________________________________________________________________");



	//////////////////ACTUAL ANALYSIS STARTS////////////////////////////////////////////
	
	int count1=0;
	int MSA_actual_templatelen[MSA_tempcount];int MSA_actual_targetlen;
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;count1=0;
		for(j=0;j<MSA_templatelen[i];j++)
		{
			if(MSA_templatearray[i][j]!='-')
			count++;
		}
		for(k=0;k<MSA_templatelen[i];k++)
		{
			if(MSA_targetarray[k]!='-')
			count1++;
		}
		
		
		MSA_actual_templatelen[i]=count;
		MSA_actual_targetlen=count1;
	}	
	
	int tt_length_difference[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{	
		tt_length_difference[i]= abs(MSA_actual_templatelen[i] - MSA_actual_targetlen);
		//printf("\nTemplate:%s has actual_length_diff=%d",MSA_tempnames[i],tt_length_difference[i]);
	}


	//Template Length consideration from target start and end length
	int target_start_end_based_template_actual_length[MSA_tempcount];
	count=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;
		for(j=MSA_igstart_target; j<MSA_egstart_target;j++)
		{
			if(MSA_templatearray[i][j]!='-')
			count++;
		}
		target_start_end_based_template_actual_length[i]=count;
		//printf("\nTemplate:%s has target start_end_based_actual_length=%d",MSA_tempnames[i], 				target_start_end_based_template_actual_length[i]);
	}

	int tt_length_difference1[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{	
	   tt_length_difference1[i]= target_start_end_based_template_actual_length[i] - MSA_actual_targetlen;
	   //printf("\nTemplate:%s has target_start_end_based_length_diffelen=%d",MSA_tempnames[i], 				tt_length_difference1[i]);
	}


	int seed_hit_length_difference[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{	
		seed_hit_length_difference[i]=MSA_actual_templatelen[i]-MSA_actual_templatelen[0];
		if(seed_hit_length_difference[i] < 0)
		seed_hit_length_difference[i]= seed_hit_length_difference[i] * (-1);
		printf("\nTemp:%s has seed_hit_length_difference:%d",MSA_tempnames[i],seed_hit_length_difference[i]);
	}



	//printf("\n\n\t\tIDENTITY ANALYSIS FOR TEMPLATES AGAINST TARGET");
	// Arrays ttident[tempcount] is for target-template identity count and their locations are in 			         ttidentpos[tempcount][templatelen[0]];template sequence is from 6th position to the target
	int MSA_ttident[MSA_tempcount];count=0;int MSA_ttidentpos[MSA_tempcount][MSA_targetlen]; 		k1=0;count1=0;

	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;count1=0;
		for(j=0,k=0;	j<MSA_targetlen,k<MSA_templatelen[i];	j++,k++)
		{
			if((MSA_targetarray[j]==MSA_templatearray[i][k]) && (MSA_targetarray[j]!='-') && 
			   (MSA_templatearray[i][k]!='-')) 
			{
					MSA_ttidentpos[i][count]=k;
					//printf("\nTemplate %s sequence has %c identical residue: %d",MSA_tempnames[i],
					//MSA_templatearray[i][j],MSA_ttidentpos[i][count]);
					count++;
			}
		}
		MSA_ttident[i]=count;
	}	
	




	count=0;
	int seed_template_target_aligned_positions[MSA_targetlen];
	for(j=0;j<MSA_targetlen;j++)
	seed_template_target_aligned_positions[j]=4444;
	
	int MSA_tt_aligned_residues_count[MSA_tempcount];
	int seed_template_target_aligned_residues=0;int count21=0;
	count=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;
		for(j=0;j<MSA_targetlen;j++)
		{
			if(      (MSA_templatearray[i][j]!='-') && (MSA_targetarray[j]!='-') && (i==0) )
			{
				seed_template_target_aligned_positions[count21]=j;
				count21++;
			}
			else if( (MSA_templatearray[i][j]!='-') && (MSA_targetarray[j]!='-') && (i>0) )
			{
				count++;
			}
		}
		MSA_tt_aligned_residues_count[i]=count;
		printf("\nHit:%s TT_res:%d",MSA_tempnames[i],MSA_tt_aligned_residues_count[i]);
	}
	seed_template_target_aligned_residues=count21;
	MSA_tt_aligned_residues_count[0]=seed_template_target_aligned_residues;

	printf("\nSeed:%s   seed_template_target_aligned_residues=:%d, TT_res:%d",MSA_tempnames[0], 			 
        seed_template_target_aligned_residues,MSA_tt_aligned_residues_count[i]);
	

	int MSA_st_hit_aligned_residues_count[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{	
		count=0;
		for(j=0;j<MSA_templatelen[i];j++)
		{
			if( (MSA_templatearray[i][j]!='-') && (MSA_templatearray[0][j]!='-'))
			count++;
		}
		MSA_st_hit_aligned_residues_count[i]=count;
	printf("\nTemplate:%s,MSA_seed_template_target_aligned_residues[i]=:%d",MSA_tempnames[i],          		
        MSA_st_hit_aligned_residues_count[i]);
	}








	
	

	
	
	float a1=0;float b1=0;
	//Identity percentage Calculation
	float MSA_ttidentpercent[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		a1=2*MSA_ttident[i];
	//	b1=2*MSA_tt_aligned_residues_count[i];
		b1=MSA_actual_targetlen + MSA_actual_templatelen[i];
		MSA_ttidentpercent[i]=(a1/b1)*100;
		//printf("\nTEMPLATE %s HAS %5d ident residues with percentage %8.3f",MSA_tempnames[i],MSA_ttident[i], 
		//MSA_ttidentpercent[i]);
	}
	//printf("\n");
	
	
	





	//Identity of templates with seed template
	//printf("\n\n\t\tIDENTITY ANALYSIS FOR TEMPLATES AGAINST SEED TEMPLATE");
	count=0;k1=0;count1=0;
	int MSA_profile_ttident[MSA_tempcount];	//Identity in seed template, hit and target
	int MSA_st_ttident[MSA_tempcount];		//Identity of template hit against seed template

	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;count1=0;
		for(j=0,k=0;	j<MSA_targetlen,k<MSA_templatelen[i];	j++,k++)
		{
			//Considered residue is same in template and target sequences
			if((MSA_targetarray[j]==MSA_templatearray[0][k]) && (MSA_templatearray[i][k]!='-') && 
			   (MSA_targetarray[j]!='-') && (MSA_templatearray[i][k]==MSA_templatearray[0][k])) 
			{
				count++;
			}
	
			if((MSA_templatearray[i][k]==MSA_templatearray[0][k]) && (MSA_templatearray[i][k]!='-') && 
			   (MSA_targetarray[j]!='-')) 
			{
				count1++;
			}
	
		}
		MSA_profile_ttident[i]=count;
		MSA_st_ttident[i]=count1;
	}


	a1=0;b1=0; 
	//Identity percentage Calculation
	float MSA_profile_ttidentpercent[MSA_tempcount],MSA_st_ttidentpercent[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		a1=3*MSA_profile_ttident[i];
		b1=MSA_actual_targetlen + MSA_actual_templatelen[i] + MSA_actual_templatelen[0];
		MSA_profile_ttidentpercent[i]=(a1/b1)*100;
		printf("\nTEMPLATE %s HAS %8.3f Percent identical residues in profile",MSA_tempnames[i],
		MSA_profile_ttidentpercent[i]);
	}	


	for(i=0;i<MSA_tempcount;i++)
	{
		a1=2*MSA_st_ttident[i];
		b1=2*MSA_st_hit_aligned_residues_count[i];
		MSA_st_ttidentpercent[i]=(a1/b1)*100;
		printf("\nTEMPLATE %s HAS %8.3f Percent identical residues with seed template",MSA_tempnames[i], 
		MSA_st_ttidentpercent[i]);
	}	
		

	




	//printf("\n\n\t\tCONTINUOUS GAP ANALYSIS OF TEMPLATES AGAINST TARGET");
	int nogap=0;
	int x=0;int acount=0;int totcount=0;int MSA_template_indel_gappos[MSA_tempcount][5000];
	int MSA_template_indel_gaploc_count[MSA_tempcount];int MSA_gaploc_count=0;int x1=0;

	int MSA_gapchunk_endpoint[MSA_tempcount][MSA_targetlen];int MSA_chunks_count[MSA_tempcount];

	for(i=0;i<MSA_tempcount;i++)
	{
		nogap=0;
		for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_templatelen[i];	j++,k++)
		{
			if(MSA_templatearray[i][k]!='-')
			nogap++;
			if(MSA_templatearray[i][k]=='-')
			{
			  if(MSA_templatearray[i][k+1]=='-')
			  acount++;
			  else
			    {
				acount=acount+1;
				totcount=totcount+acount;
				MSA_template_indel_gappos[i][x]=acount;
		  		//printf("\naTemplate %s has indel_gappos: %d gaps",MSA_tempnames[i], 					MSA_template_indel_gappos[i][x]);
				MSA_gapchunk_endpoint[i][x]=k;
				//printf("\nTemplate %s has MSA_gapchunk_endpoint: %d",MSA_tempnames[i],				MSA_gapchunk_endpoint[i][x]);
				MSA_gaploc_count++;
			  	//printf("\tNext char: %c%c%c",MSA_templatearray[i][k+1],MSA_templatearray[i][k+2], 					MSA_templatearray[i][k+3]);
				x++;x1++;
				acount=0;
			     }
			     //x1++;
			}
		x1=0;
		}
		if(nogap==MSA_templatelen[i])
		{
			MSA_template_indel_gaploc_count[i]=0;
			//printf("\naTemplate %s has indel_gappos[i][x]: %d gaps",MSA_tempnames[i],				MSA_template_indel_gaploc_count[i]);
		}
		acount=0;
		MSA_template_indel_gaploc_count[i]=MSA_gaploc_count;
		if(MSA_template_indel_gaploc_count[i]==0)
		{
			MSA_template_indel_gaploc_count[i]=0;
			MSA_template_indel_gappos[i][0]=0;
		}
	
		MSA_chunks_count[i]=MSA_template_indel_gaploc_count[i]+1;
		if((MSA_templatearray[i][0]=='-') ||(MSA_templatearray[i][MSA_templatelen[i]-1]=='-'))
		MSA_chunks_count[i]=MSA_chunks_count[i] - 1;
	
		if((MSA_templatearray[i][0]=='-') && (MSA_templatearray[i][MSA_templatelen[i]-1]=='-'))
		MSA_chunks_count[i]=MSA_chunks_count[i] - 1;
	
		MSA_gaploc_count=0;x=0;
	}	
	
	//printf("\n---------------------------------------------------------------------------------");
	//printf("\n\n\n");
	//for(i=0;i<MSA_tempcount;i++)
	//{
	   // printf("\nTemplate:%s\t\tindel_gaploc_count[i]=%d-for gap lengths:",MSA_tempnames[i],				MSA_template_indel_gaploc_count[i]); 
		//for(x=0;x<MSA_template_indel_gaploc_count[i];x++)
		//printf("%d,",MSA_template_indel_gappos[i][x]);
	//}	
	



	int MSA_gapchunk_startpoint[MSA_tempcount][MSA_targetlen];
	for(i=0;i<MSA_tempcount;i++)
	{
		//printf("\nMSA_Template %s has %d gap chunks from",MSA_tempnames[i],MSA_template_indel_gaploc_count[i]);
		for(j=0;j<MSA_template_indel_gaploc_count[i];j++)
		{
			MSA_gapchunk_startpoint[i][j]=MSA_gapchunk_endpoint[i][j]-MSA_template_indel_gappos[i][j]+1;
		//printf("\n\t\t%d\tStart:%2d\tEnd:%2d",j+1,MSA_gapchunk_startpoint[i][j],MSA_gapchunk_endpoint[i][j]);
		}
	}



	//MSA_gapchunk_startpoint[i][j],MSA_gapchunk_endpoint[i][j],
	//printf("\n____________________________________________________________________________________________________");
	int MSA_reschunk_startpoint[MSA_tempcount][5000];int MSA_reschunk_endpoint[MSA_tempcount][5000];x=0;
	int MSA_reschunk_count[MSA_tempcount];a1=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		x=0;
		for(j=0;j<MSA_template_indel_gaploc_count[i];j++)
		{
			if((j==0))		
			{
				//printf("\nTemplate %s has res chunks with residue stretches from",MSA_tempnames[i]);
	
				if((MSA_gapchunk_startpoint[i][j]==0) && (MSA_gapchunk_startpoint[i][j+1]!=0) && 
				  (MSA_template_indel_gaploc_count[i]>1))
				{
					MSA_reschunk_startpoint[i][x]=MSA_gapchunk_endpoint[i][j]+1;
					MSA_reschunk_endpoint[i][x]=MSA_gapchunk_startpoint[i][j+1]-1;
					//printf("\n%2d\tn1Start:%2d\tEnd:%2d",x+1,MSA_reschunk_startpoint[i][x],
					//MSA_reschunk_endpoint[i][x]);	
					x++;
				}
	
				else if((MSA_gapchunk_startpoint[i][j]==0) && (MSA_template_indel_gaploc_count[i]==1))
				{
					MSA_reschunk_startpoint[i][x]=MSA_gapchunk_endpoint[i][j]+1;
					MSA_reschunk_endpoint[i][x]=MSA_templatelen[i]-1;
					//printf("\n%2d\tn111Start:%2d\tEnd:%2d",x+1,MSA_reschunk_startpoint[i][x],
					//MSA_reschunk_endpoint[i][x]);	
					x++;
				}
	
	
				else if(MSA_template_indel_gaploc_count[i]==0)
				{
					MSA_reschunk_startpoint[i][x]=0;
					MSA_reschunk_endpoint[i][x]=MSA_templatelen[i]-1;
					//printf("\n%2d\tn2Start:%2d\tEnd:%2d",x+1,MSA_reschunk_startpoint[i][x],
					//MSA_reschunk_endpoint[i][x]);	
					x++;
				}			
			}
	
	
			if((MSA_gapchunk_startpoint[i][j]>0) && (j==0) && (MSA_gapchunk_startpoint[i][j]!=0)&&   				(MSA_template_indel_gaploc_count[i]>0))
			{
			  MSA_reschunk_startpoint[i][x]=0;
			  MSA_reschunk_endpoint[i][x]=MSA_gapchunk_startpoint[i][j]-1;
	 	      //printf("\n%2d\ta3Start:%2d\tEnd:%2d",x+1,MSA_reschunk_startpoint[i][x],MSA_reschunk_endpoint[i][x]);
			  x++;
		  	}
		



			if((MSA_gapchunk_startpoint[i][j]>0) &&  (MSA_gapchunk_endpoint[i][j]<MSA_templatelen[i])  && 
			    (j==(MSA_template_indel_gaploc_count[i]-1))) 

			{			
				MSA_reschunk_startpoint[i][x]=MSA_gapchunk_endpoint[i][j]+1;
				MSA_reschunk_endpoint[i][x]=MSA_templatelen[i]-1;
				if(MSA_reschunk_startpoint[i][x] <= MSA_reschunk_endpoint[i][x])
				{ 
					//printf("\n%2d\tc3Start:%2d\tEnd:%2d",x+1,MSA_reschunk_startpoint[i][x],					MSA_reschunk_endpoint[i][x]);
					x++;
				}
			}


			 if((MSA_gapchunk_startpoint[i][j]>0) && (MSA_gapchunk_endpoint[i][j]<MSA_templatelen[i]) && 
			    (MSA_reschunk_startpoint[i][j+1]<MSA_templatelen[i]) && 
			    (j<(MSA_template_indel_gaploc_count[i]-1)))
			{
				  MSA_reschunk_startpoint[i][x]=MSA_gapchunk_endpoint[i][j]+1;
				  MSA_reschunk_endpoint[i][x]=MSA_gapchunk_startpoint[i][j+1] - 1;
				  //printf("\n%2d\ta31	Start:%2d\tEnd:%2d",x+1,
				  //MSA_reschunk_startpoint[i][x],MSA_reschunk_endpoint[i][x]);
				  x++;
		  	}
		}
		MSA_reschunk_count[i]=x;
	}





	//printf("\n____________________________________________________________________________________________________");
	//for(i=0;i<MSA_tempcount;i++)
	//{
	//	printf("\nTemplate %s has %d res chunks with stretches from",MSA_tempnames[i],MSA_reschunk_count[i]);
	//	for(j=0;j<MSA_reschunk_count[i];j++)
	//	{
	//		printf("\n%2d:Start=%2d\tEnd=%2d",j,MSA_reschunk_startpoint[i][j],MSA_reschunk_endpoint[i][j]);
	//	}
	//}


	//printf("\n____________________________________________________________________________________________________");
	int MSA_temp_chunkcentres[MSA_tempcount][MSA_targetlen];
	int MSA_temp_chunklengths[MSA_tempcount][MSA_targetlen];
	for(i=0;i<MSA_tempcount;i++)
	{
		//printf("\nTemplate %s has %d res chunks with residue stretches from",MSA_tempnames[i],
		//MSA_reschunk_count[i]);
		for(j=0;j<MSA_reschunk_count[i];j++)
		{
			MSA_temp_chunklengths[i][j]=MSA_reschunk_endpoint[i][j] - MSA_reschunk_startpoint[i][j] + 1;
	
			if((MSA_temp_chunklengths[i][j]>3) && ((MSA_temp_chunklengths[i][j]%2)==0))
			MSA_temp_chunkcentres[i][j]= MSA_reschunk_startpoint[i][j] + MSA_temp_chunklengths[i][j]/2;
	
			if((MSA_temp_chunklengths[i][j]>3) && ((MSA_temp_chunklengths[i][j]%2)==1))
			MSA_temp_chunkcentres[i][j]= MSA_reschunk_startpoint[i][j] + (MSA_temp_chunklengths[i][j])/2;

			if(MSA_temp_chunklengths[i][j]==3)
			MSA_temp_chunkcentres[i][j]= MSA_reschunk_startpoint[i][j]+1;

			if((MSA_temp_chunklengths[i][j]==2) || (MSA_temp_chunklengths[i][j]==1))
			MSA_temp_chunkcentres[i][j]= MSA_reschunk_startpoint[i][j];
		
			//printf("\n%2d:Start=%4d\tEnd=%4d\tChunklength=%4d\tchunkcentre=%4d",j+1,
			//MSA_reschunk_startpoint[i][j],MSA_reschunk_endpoint[i][j],MSA_temp_chunklengths[i][j],
			//MSA_temp_chunkcentres[i][j]);
		}
	}


	
	//printf("\n____________________________________________________________________________________________________");
	int MSA_chunks_commonsites[MSA_tempcount];int n1,n2,n3,n4=0;
	float alignedchunklength_templates[MSA_tempcount];
	float a21,a22=0; a21=a22=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;a1=0;
		for(j=0,k=0;	j<MSA_reschunk_count[i],k<MSA_reschunk_count[0];	j++,k++)		
		//j is running for all other templates other than seed template & K is running for seed template
		{
			n1=abs(MSA_reschunk_endpoint[i][j]-MSA_reschunk_endpoint[0][k]);
			n2=abs(MSA_reschunk_startpoint[i][j]-MSA_reschunk_startpoint[0][k]);
			n3=abs(MSA_reschunk_endpoint[i][j] - MSA_reschunk_startpoint[i][j+1]);
			n4=abs(MSA_reschunk_endpoint[0][j]-MSA_reschunk_startpoint[0][k+1]);

			if((n1<=2) || (n2<=2) || (n3<=2)|| (n4<=2))	
			{
				count++;
				a21=a21+MSA_temp_chunklengths[i][j];
			}
		}
		MSA_chunks_commonsites[i]=count;
		alignedchunklength_templates[i]=a21;
		printf("\nTemplate %s has %d common location sites",MSA_tempnames[i],MSA_chunks_commonsites[i]);
	}
	//system("clear");	



	k1=0;
	float ave_MSA_temp_chunklengths[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		a21=0;
		for(j=0;j<MSA_reschunk_count[i];j++)
		{
			k1=MSA_reschunk_endpoint[i][j] - MSA_reschunk_startpoint[i][j] + 1;
			if(k1>=5)   
			a21=a21+k1;
		}
		a22=MSA_reschunk_count[i];
		if(a21==0)
		a21=1;
		if(a22==0)
		a22=1;
		ave_MSA_temp_chunklengths[i]=a21/a22;
		printf("\nTemp:%s has a21:%f,a22:%f, ave_MSA_temp_chunklengths[i]:%f",MSA_tempnames[i],
		a21,a22,ave_MSA_temp_chunklengths[i]);
	}


	
	float ave_MSA_chunklength_based_distance[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		if(i==0)
		ave_MSA_chunklength_based_distance[i]=0;
		else if(i>0)
		{
			ave_MSA_chunklength_based_distance[i]=ave_MSA_temp_chunklengths[i] - ave_MSA_temp_chunklengths[0];
		}
	if(ave_MSA_chunklength_based_distance[i]<0)
	ave_MSA_chunklength_based_distance[i]=ave_MSA_chunklength_based_distance[i]*(-1);
	printf("\nTemplate %s has i:%f, Seed:%f\t ave_MSA_chunklength_based_distance = %f",MSA_tempnames[i],
	ave_MSA_temp_chunklengths[i], ave_MSA_temp_chunklengths[0], ave_MSA_chunklength_based_distance[i]);
	}


	//printf("\n___________________________________________________________________________________________________");


	for(i=0;i<MSA_tempcount;i++)
	{
		//printf("\nTemplate %s has %d res chunks with residue stretches from",MSA_tempnames[i],
		//MSA_reschunk_count[i]);
		for(j=0;j<MSA_reschunk_count[i];j++)
		{
			MSA_reschunk_startpoint[i][j]=MSA_reschunk_startpoint[i][j]+1;
			//printf("\n%2d:Start=%2d\tEnd=%2d",j+1,MSA_reschunk_startpoint[i][j],MSA_reschunk_endpoint[i][j]);
		}
	}




	//MSA_temp_chunkcentres[i][j]
	int a11, b11,c1,d1=0;
	//printf("\n____________________________________________________________________________________________________");
	float MSA_chunk_lendiff[MSA_tempcount];int MSA_aligned_commonsites[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;
		for(j=0;j<MSA_reschunk_count[i];j++)
		{
			for(k=0;k<MSA_reschunk_count[0];k++)
			{
				a11=MSA_temp_chunkcentres[i][j];
				b11=MSA_temp_chunkcentres[0][k];
	
				//Check this (abs(a11-b11)<=10) condition if problem arises
				if((MSA_templatearray[i][a11]!='-') && (MSA_templatearray[0][b11]!='-')  )
				{
					count++;	
					c1=fabs(MSA_reschunk_startpoint[i][j] - MSA_reschunk_startpoint[0][k]);
					d1=fabs(MSA_reschunk_endpoint[i][j] -MSA_reschunk_endpoint[0][k]);
					c1=c1+d1;
				}
			}
			MSA_chunk_lendiff[i]=c1;				
		}
		MSA_aligned_commonsites[i]=count;	
		//printf("\nTemplate %s has %d common location sites",MSA_tempnames[i], MSA_aligned_commonsites[i]);
	}





	//printf("\n\n\t\tCONTINUOUS GAP ANALYSIS OF TARGET");
	nogap=0;
	x=0;acount=0;totcount=0;int MSA_target_indel_gappos[5000];
	int MSA_target_indel_gaploc_count;MSA_gaploc_count=0;int MSA_gap_loci[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		nogap=0;
		for(j=MSA_igstart_target,k=MSA_igstart_target;	j<MSA_egstart_target,k<MSA_egstart_target;	j++,k++)
		{
			if(MSA_targetarray[j]!='-')
			nogap++;
			if(MSA_targetarray[j]=='-')
			{
				if(MSA_targetarray[j+1]=='-')
				{
					acount++;
				}
				else
				{
					acount=acount+1;
					totcount=totcount+acount;
					MSA_target_indel_gappos[x]=acount;
					//printf("\natarget %s has indel_gappos: %d gaps",MSA_tempnames[i],
					//MSA_target_indel_gappos[x]);
					MSA_gaploc_count++;
			  	        //printf("\tNext char: %c%c%c",MSA_targetarray[k+1],MSA_targetarray[k+2],
					//MSA_targetarray[k+3]);
					x++;
					acount=0;
				}
			}
		}
		if(nogap==MSA_targetlen)
		{
			MSA_target_indel_gaploc_count=0;
			//printf("\natarget %s has indel_gappos[i][x]: %d gaps",MSA_tempnames[i],
			//MSA_target_indel_gaploc_count);
		}
		acount=0;
		MSA_target_indel_gaploc_count=MSA_gaploc_count;
		MSA_gaploc_count=0;x=0;
	}


	//printf("\n\n\n");
	//printf("\ntarget:%s\t\tindel_gaploc_count[i]=%d-for gap lengths:",MSA_tempnames[i],   				MSA_target_indel_gaploc_count); 
	//for(x=0;x<MSA_target_indel_gaploc_count;x++)
	//printf("%d,",MSA_target_indel_gappos[x]);
	for(i=0;i<MSA_tempcount;i++)
	{
		MSA_gap_loci[i]=(MSA_template_indel_gaploc_count[i] + MSA_target_indel_gaploc_count);
		//printf("\nTemplate %s has Template MSA_gap_loci:%d              Target MSA Gap Loci%d",MSA_tempnames[i], 			MSA_reschunk_count[i],MSA_target_indel_gaploc_count);
	}

	float MSA_unspanned_residues[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
	  count=0;
	  for(j=0;j<MSA_templatelen[i];j++)
	  {
	      if( ((MSA_targetarray[j]=='-') && (MSA_templatearray[i][j]!='-') && (MSA_templatearray[0][j]=='-') ) ||	
	          ((MSA_templatearray[i][j]=='-') && (MSA_targetarray[j]!='-') && (MSA_templatearray[0][j]=='-')) )
	 	count++;
	  }
	  a1=count;
	  b1=MSA_templatelen[i];
	  //b1=MSA_actual_templatelen[i];  //It doesn't work
	  MSA_unspanned_residues[i]=a1/b1;
	}









	//stbtsc=Seed Template Based Template Span_Combination
	count=0;count1=0;int count2=0;int l=0;
	int stbtsc_template_res_target_res[MSA_tempcount];int count4=0;
	int stbtsc_template_res_target_gap[MSA_tempcount];int count5=0;
	int stbtsc_template_gap_target_res[MSA_tempcount];int count6=0;
	int stbtsc_template_gap_target_gap[MSA_tempcount];int count7=0;

	for(l=0;l<MSA_tempcount;l++)
	{
		for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_targetlen;	j++,k++)
		{
			if(  (MSA_templatearray[0][j]=='-') && (MSA_templatearray[l][j]!='-') && (MSA_targetarray[j]!='-'))
			count4++;
			if(  (MSA_templatearray[0][j]=='-') && (MSA_templatearray[l][j]!='-') && (MSA_targetarray[j]=='-'))
			count5++;
			if(  (MSA_templatearray[0][j]=='-') && (MSA_templatearray[l][j]=='-') && (MSA_targetarray[j]!='-'))
			count6++;
			if(  (MSA_templatearray[0][j]=='-') && (MSA_templatearray[l][j]=='-') && (MSA_targetarray[j]=='-'))
			count6++;
		}
		stbtsc_template_res_target_res[l]=count4;
		stbtsc_template_res_target_gap[l]=count5;
		stbtsc_template_gap_target_res[l]=count6;
		stbtsc_template_gap_target_gap[l]=count7;
		count=0;count1=0;count4=0;count5=0;count6=0;count7=0;
	}

	printf("\n\n\t\t\t\tSEED TEMPLATE BASED OTHER TEMPLATE COMBINATION ANALYSIS");
	printf("\nTE: TEMPLATE     TA: TARGET      SEGAP= SEED TEMPLATE GAPS       RES: RESIDUES");
	printf("\n\n            |   ALIGNED  |     ALIGNED    |   ALIGNED     |  ALIGNED      ");
	printf("\n   TEMPLATE | TE_TA_RES  | TE_RES_TA_GAP  | TE_GAP_TA_RES | TE_GAP_TA_GAP");
	printf("\n            | WITH SEGAP |   WITH SEGAP   |  WITH SEGAP   | WITH SEGAP       | SUM");
	printf("\n____________________________________________________________________________________________________");
	for(l=0;l<MSA_tempcount;l++)
	{
		j=stbtsc_template_res_target_res[l]+stbtsc_template_res_target_gap[l]+stbtsc_template_gap_target_res[l]+ 
		stbtsc_template_gap_target_gap[l];
		printf("\n%2d %s    |%8d    | %8d       | %6d        | %6d           |%4d",l+1,MSA_tempnames[l],
		stbtsc_template_res_target_res[l], stbtsc_template_res_target_gap[l],stbtsc_template_gap_target_res[l], 		stbtsc_template_gap_target_gap[l],j);
	}	
	printf("\n__________________________________________________________________________________________________\n");





	a1=0,b1=0;
	float average_fold_length[MSA_tempcount];count=0;
	for (i=0;i<MSA_tempcount;i++)
	{	
		if(i==0)
		{
			a1=seed_template_target_aligned_residues;
			b1=(MSA_template_indel_gaploc_count[i] + MSA_target_indel_gaploc_count);
			//printf("\nA1:%f,b1:%f",a1,b1);
			if(b1==0)		
			b1=b1 + 1;
			average_fold_length[i]=a1/b1;
		}
	
		if(i>0)
		{
			a1=MSA_tt_aligned_residues_count[i];
			b1=(MSA_template_indel_gaploc_count[i] + MSA_target_indel_gaploc_count);
			//printf("\nA1:%f,b1:%f",a1,b1);
			if(b1==0)		
			b1=b1 + 1;
			average_fold_length[i]=a1/b1;
		}
		//printf("\nTemplate:%s average_fold_length: %f",MSA_tempnames[i],average_fold_length[i]);
		count=0;
	}







//MSA_reschunk_count[i], MSA_reschunk_startpoint[i][j], MSA_reschunk_endpoint[i][j],
//MSA_chunks_commonsites[i]
//ave_MSA_temp_chunklengths[i],ave_MSA_chunklength_based_distance[i]
//MSA_reschunk_count[i], MSA_chunk_lendiff[i]
//average_fold_length[i]



	i=0;j=0;l=0;count=0;int swap1=0;a1=0;b1=0;int stbtsc_diff[MSA_tempcount];
	float returnscore;float MSA_Score1[MSA_tempcount];	//Needed Later in the currently commented modules at end
	for(i=0;i<MSA_tempcount;i++)
	{
	   j=(stbtsc_template_res_target_res[0] + stbtsc_template_res_target_gap[0] + stbtsc_template_gap_target_res[0]);
  	   l=(stbtsc_template_res_target_res[i] + stbtsc_template_res_target_gap[i] + stbtsc_template_gap_target_res[i]);
	   stbtsc_diff[i]=j-l;
	   if(stbtsc_diff[i]<0)
	   stbtsc_diff[i]=stbtsc_diff[i]*(-1);
	   //printf("\nTemplate:%s has stbtsc_diff[i]:%d",MSA_tempnames[i],stbtsc_diff[i]);
	}




	//BLOSUM62 Score of a hit to target
	float fswap=0;float MSA_tt_blosum62score[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;fswap=0;
		for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_targetlen;	j++,k++)
		{	
			// Identity Scores
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+9;
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+8;
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+7;
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+11;
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+7;
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+4;
	
	
			//Uptil 5th Row Horizontal lines
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(1);	
	
	
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(1);	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);	

			//6th Row Horizontal lines
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(0);	

			//7th Row Horizontal lines FROM N
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(1);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(0);

			//Edited till here for the main() gap
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);	
	
			//8th Row Horizontal lines FROM D
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(1);	

			//9th Row Horizontal lines FROM E
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-4);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(2);	

			//10th Row Horizontal lines from Q
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(2);	

			//11th Row Horizontal lines from H
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(0);	

			//12th Row Horizontal lines from R

			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(0);	
	
	
	
			//////////////////////////////////////////////K STARTS

			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(2);	

			// M STARTS
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	


			//I STARTS
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(1);	
	
			//L STARTS

			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(2);	
	
			//V STARTS
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(3);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(1);	
	
			//F STARTS
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(0);	


			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-1);	

			//Y STARTS
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	


			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	


			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(3);
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(3);	


			//W STARTS
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(2);	
		}
		a1=2*fswap;
		b1=2*MSA_tt_aligned_residues_count[i]+1;
		//b1=MSA_actual_targetlen + MSA_actual_templatelen[i];        //It doesn't work

		MSA_tt_blosum62score[i]=a1/b1;
		//if(MSA_tt_blosum62score[i]<0)
		//MSA_tt_blosum62score[i]=log(-MSA_tt_blosum62score[i]);	
		//printf("\nTemplate:%s,tt_BLOSUM62_Score:%f",MSA_tempnames[i],MSA_tt_blosum62score[i]);
	}	











	//BLOSUM62 Score of a hit to the seed template
	fswap=0;float MSA_st_blosum62score[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;fswap=0;
		for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_templatelen[0];	j++,k++)
		{	
	
		// Identity Scores
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+9;
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+8;
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+7;
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+11;
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+7;
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+4;


			//Uptil 5th Row Horizontal lines
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(1);	
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);	

			//6th Row Horizontal lines
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(0);	

			//7th Row Horizontal lines FROM N
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(1);	
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(0);	

			//8th Row Horizontal lines FROM D
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(1);	
	
			//9th Row Horizontal lines FROM E
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-4);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(2);	
	
			//10th Row Horizontal lines from Q
			//Edited till here
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(2);	

			//11th Row Horizontal lines from H
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(0);	

			//12th Row Horizontal lines from R

			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(0);	
	
	
	
			//////////////////////////////////////////////K STARTS

			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(2);	

			// M STARTS
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);	
	
			//I STARTS
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(1);	
	
			//L STARTS
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(2);	
	
			//V STARTS
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-3);	
	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(3);
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(1);	
	
			//F STARTS
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(-1);	

			//Y STARTS
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-1);	
	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(3);
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(3);	
	
	
			//W STARTS
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='S')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='S') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='P')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='P') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='A')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='A') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='N')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='N') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='D')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='H')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='H') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='M')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='M') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='I')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='I') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='L')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='L') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='V')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='F')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='F') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(1);	

			if((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][k]=='Y')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='Y') && (MSA_templatearray[0][k]=='W')) 
			fswap=fswap+(2);	
		}
		a1=2*fswap;
		b1=2*MSA_st_hit_aligned_residues_count[i];
		//b1=MSA_actual_templatelen[0] + MSA_actual_templatelen[i]; //It doesn't work. 

		MSA_st_blosum62score[i]=a1/b1;
		//if(MSA_st_blosum62score[i]<0)
		//MSA_st_blosum62score[i]=log(-MSA_st_blosum62score[i]);
		//printf("\nTemplate:%s,tt_BLOSUM62_Score:%f,st_BLOSUM62_Score:%f",MSA_tempnames[i],MSA_tt_blosum62score[i],
		//MSA_st_blosum62score[i]);
	}	









	count=0;int additional_span[MSA_tempcount];float additional_span_percentage[MSA_tempcount];
	int additional_span_identity[MSA_tempcount];float additional_span_identity_percentage[MSA_tempcount];
	int seed_unaligned_tt_residues=0;
	//Starts from 2nd template onwards leaving the seed hit
	//Finding the number of target residues,still unaligned with the seed template.
	count=0;
	for(j=0;j<MSA_templatelen[0];j++)
	{
		if((MSA_targetarray[j]!='-') && (MSA_templatearray[0][j]=='-'))
		count++;
	}
	seed_unaligned_tt_residues=count;
	//printf("\nADDITIONAL SPAN ANALYSIS OF TEMPLATES OVER THE SEED HIT"); 
	//printf("\nSTILL UNALIGNED TARGET RESIDUES WITH THE SEED TEMPLATE: %d",seed_unaligned_tt_residues); 


	int additional_span_position[MSA_tempcount][MSA_targetlen];
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_templatelen[i];j++)
		additional_span_position[i][j]=(-1);
	}
	
	count1=0;count2=0;i=0;j=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_templatelen[i];j++)
		{
			if((MSA_targetarray[j]!='-') && (MSA_templatearray[0][j]=='-') && (MSA_templatearray[i][j]!='-'))
			{
				additional_span_position[i][j]=j;
				count1++;
				if(MSA_targetarray[j]==MSA_templatearray[i][j])
				count2++;
			}
		}
		additional_span[i]=count1;
		additional_span_identity[i]=count2;
		count1=0;count2=0;

		if(seed_unaligned_tt_residues==0)
		{
			additional_span_percentage[i]=0;
			additional_span_identity_percentage[i]=0;
		}
		else if(seed_unaligned_tt_residues > 0)
		{
			a1=additional_span[i];
			additional_span_percentage[i]=(a1/seed_unaligned_tt_residues)*100;
	
			b1=additional_span_identity[i];
			additional_span_identity_percentage[i]=(b1/seed_unaligned_tt_residues)*100;
		}
	}

	//ADDITIONAL SPAN ANALYSIS OF TEMPLATES OVER THE SEED HIT Ends here


	
	

	//for(i=0;i<MSA_tempcount;i++)
	//printf("\nTemplate:%s, Additional_Span=%d,Additional_Span_Identity=%d",MSA_tempnames[i],additional_span[i], 		additional_span_identity[i]);





	//Finding Unique Residues in every template, for which only a template has a residue against a target residue, 			and seed,other template hits have a gap.
	int unique_residues[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	unique_residues[i]=(-1);

	count=0;count1=0;
	for(i=1;i<MSA_tempcount;i++)
	{
		count1=0;
		for(j=0;j<MSA_templatelen[i];j++)
		{
			if(  (MSA_targetarray[j]!='-') && (MSA_templatearray[0][j]=='-'))
			{
				if(MSA_templatearray[i][j]!='-')
				{
					count=0;
					for(k=0;k<MSA_tempcount;k++)
					{
						if(  (MSA_templatearray[k][j]!='-') && (k!=i) )	
						count++;
					}
					if(count==0)
					count1++;
				}
			}
		}
		unique_residues[i]=count1;
		//printf("\nTemplate:%s has unique residues:%d",MSA_tempnames[i],unique_residues[i]);	
	}
	//Finding Unique Residues in every template, for which only a template has a residue against a target residue, 			and seed,other template hits have a gap Done here.





	//Find overlap of each template with the seed template for all the remaining templates
	int MSA_st_gap_overlap[MSA_tempcount-1];count1=0;count2=0;
	int MSA_st_gap_overlap_target_residue[MSA_tempcount];int MSA_st_gap_overlap_target_gap[MSA_tempcount];

	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;count1=0;count2=0;
	for(j=MSA_igstart_template[i],k=MSA_igstart_target;  j<MSA_egstart_template[i],k<MSA_egstart_target; 	j++,k++)
		{
			if ( (MSA_templatearray[0][j]=='-') && (MSA_templatearray[i][j]!='-') )
			count++;
		}
		MSA_st_gap_overlap[i-1]=count;

		for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_targetlen;	j++,k++)
		{
			if ( (MSA_templatearray[0][j]=='-') && (MSA_templatearray[i][j]!='-') && (MSA_targetarray[k]!='-'))
			count1++;
		}
		MSA_st_gap_overlap_target_residue[i-1]=count1;
	
		for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_targetlen;	j++,k++)
		{
			if ( (MSA_templatearray[0][j]=='-') && (MSA_templatearray[i][j]!='-') && (MSA_targetarray[k]=='-'))
			count2++;
		}
		MSA_st_gap_overlap_target_gap[i-1]=count2;
		//printf("\nTemplate %s has st_gap_Overlap:%5d,target_res=%5d,targetgap=%5d",MSA_tempnames[i],
		//MSA_st_gap_overlap[i-1],MSA_st_gap_overlap_target_residue[i-1],MSA_st_gap_overlap_target_gap[i-1]);
	}
	//Find overlap of each template with the seed template for all the remaining templates Done here





	//printf("\n\n\nSEED_TEMPLATE_GAP");
	//printf("\nTEMPLATE       OVERLAP         TARGET_RES     TARGET_GAP");
	//for(i=0;i<MSA_tempcount;i++)
	//printf("\n%s %15d %15d %15d",MSA_tempnames[i],MSA_st_gap_overlap[i-1],MSA_st_gap_overlap_target_residue[i-1],
	//MSA_st_gap_overlap_target_gap[i-1]);
	//printf("\n\n");



	float seed_template_hit_span[MSA_tempcount];count=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		a1=0;b1=0;count=0;
		for(j=0,k=0  ;j<MSA_templatelen[i],k<MSA_templatelen[0];  j++,k++)
		{
			if(  (MSA_templatearray[i][j]!='-') && (MSA_templatearray[0][k]!='-')  )
			count++;
		}
		a1=2*count;
		b1=MSA_actual_templatelen[i] + MSA_actual_templatelen[0];
		seed_template_hit_span[i]=(a1/b1)*100;
		//printf("\nCount: %d  Template %s has %f seed_hit span",count, MSA_tempnames[i],seed_template_hit_span[i]);
	}
		

	
	
	//for(i=0;i<MSA_tempcount;i++)
	//printf("\nTemplate:%s,tt_blosum62score[i]:%f,st_blosum62score[i]:%f, MSA_aligned_commonsites[i]:%d",
	//MSA_tempnames[i],MSA_tt_blosum62score[i], MSA_st_blosum62score[i],MSA_aligned_commonsites[i]); 

	int MSA_reschunk_count_difference[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		if(MSA_reschunk_count[i]==0)
		MSA_reschunk_count[i]=1;
		MSA_reschunk_count_difference[i]=MSA_reschunk_count[i]- MSA_reschunk_count[0] + 1;
		if(MSA_reschunk_count_difference[i]<0)
		MSA_reschunk_count_difference[i]=MSA_reschunk_count_difference[i]*(-1);
		//printf("\nTemplate:%s has MSA_reschunk_count_difference[i]:%d",MSA_tempnames[i], 				MSA_reschunk_count_difference[i]);
	}



	//For R,D and W,V interchangebility being less in the hit closest to the seed template
	float RDWV_seed_hit_change[MSA_tempcount];count=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;
		for(j=0;j<MSA_templatelen[i];j++)
		{
			if (    ((MSA_templatearray[i][j]=='R') && (MSA_templatearray[0][j]=='D'))  ||
				((MSA_templatearray[i][j]=='D') && (MSA_templatearray[0][j]=='R'))  ||
				((MSA_templatearray[i][j]=='W') && (MSA_templatearray[0][j]=='V'))  ||
				((MSA_templatearray[i][j]=='V') && (MSA_templatearray[0][j]=='W'))     )
			count++;
		}
		a1=2*count;
		b1=MSA_actual_templatelen[0] + MSA_actual_templatelen[i];
		RDWV_seed_hit_change[i]=(a1/b1)*100;
		printf("\nTemp%s has RDWV change:%8.3f",MSA_tempnames[i],RDWV_seed_hit_change[i]);
	}
	





	//Open this comment barrier after finishing this script
	//char new[50]="_MSA_Printfile.ali";
	//char *new1=argv[1];
	//char* new2=strcat(new1,new);
	//FILE *msaprintfile=fopen(new2,"w");
	//for(j=0;j<MSA_tempcount;j++)
	//{
	//	for(k=0;k<MSA_templatelen[j];k++)
	//	{
	//		if((k%80)==0)		
	//		fprintf(msaprintfile,"\n%s>",MSA_tempnames[j]);
	//		else
	//		fprintf(msaprintfile,"%c",MSA_templatearray[j][k]);
	//	}
	//}
	
	//for(k=0;k<MSA_targetlen;k++)
	//{
	//	if((k%80)==0)		
	//	fprintf(msaprintfile,"\n%s","TARGT>");
	//	else
	//	fprintf(msaprintfile,"%c",MSA_targetarray[k]);
	//}
	//Open this comment barrier after finishing this script






	j=0;k=0;
	//CM_RMSD58.c script based Seed-Template Hit Structural similarity Assessment Script modules

	//Creating array of PDB filenames to be opened as per the MSA Alignment file
	char MSA_pdbfiles[MSA_tempcount][20];char MSA_pdb_swap[20];
	fseek(MSA_alifile, 0, SEEK_SET);		// Seeking the cursor back to start of file
	i=0;
	while(fgets(MSA_line,sizeof(MSA_line),MSA_alifile) && (i<MSA_tempcount))
	{
		if((MSA_line[5]=='>')&&(MSA_line[0]!='\0'))
		{
			MSA_pdb_swap[0]=MSA_line[0];
			//printf("\nSwap0 for %d template=%c",i,MSA_pdb_swap[0]);
			MSA_pdb_swap[1]=MSA_line[1];
			//printf("\nSwap0 for %d template=%c",i,MSA_pdb_swap[1]);
			MSA_pdb_swap[2]=MSA_line[2];
			//printf("\nSwap0 for %d template=%c",i,MSA_pdb_swap[2]);
			MSA_pdb_swap[3]=MSA_line[3];
			//printf("\nSwap0 for %d template=%c",i,MSA_pdb_swap[3]);
			//strstr(MSA_pdb_swap, "_fit.pdb");
			if(MSA_line[4]=='A')
			{
				MSA_pdb_swap[4]='_';
				MSA_pdb_swap[5]='f';
				MSA_pdb_swap[6]='i';
				MSA_pdb_swap[7]='t';
				MSA_pdb_swap[8]='.';
				MSA_pdb_swap[9]='p';
				MSA_pdb_swap[10]='d';
				MSA_pdb_swap[11]='b';
				MSA_pdb_swap[12]='\0';
				MSA_line[4] = '\0';
			}
			else if(MSA_line[4]!='A') 
			{
				MSA_pdb_swap[4]=MSA_line[4];
				MSA_pdb_swap[5]='_';
				MSA_pdb_swap[6]='f';
				MSA_pdb_swap[7]='i';
				MSA_pdb_swap[8]='t';
				MSA_pdb_swap[9]='.';
				MSA_pdb_swap[10]='p';
				MSA_pdb_swap[11]='d';
				MSA_pdb_swap[12]='b';
				MSA_pdb_swap[13]='\0';
				MSA_line[4] = '\0';
			}
 
			strcpy(MSA_pdbfiles[i],MSA_pdb_swap);
			//printf("\nTemplate %4d:%6s\tStrlen:%d",i,MSA_pdbfiles[i],strlen(MSA_pdbfiles[i]));
			i++;
		}
	}	



	int MSA_seed_residue_aligned_positions[MSA_tempcount][MSA_targetlen];
	int MSA_temphit_residue_aligned_positions[MSA_tempcount][MSA_targetlen];
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_templatelen[i];j++)
		{
			MSA_seed_residue_aligned_positions[i][j]=-1;
			MSA_temphit_residue_aligned_positions[i][j]=-1;
		}
	}

	count=0;int MSA_seed_aligned_residues[MSA_tempcount];	
	float sc_noapoint25percent[MSA_tempcount]; 	float sc_noapoint5percent[MSA_tempcount]; 
	float sc_noa1percent[MSA_tempcount]; 		float sc_noa2percent[MSA_tempcount];  
	float sc_noa4percent[MSA_tempcount];  		float sc_noa8percent[MSA_tempcount]; 

	float ca_noapoint25percent[MSA_tempcount];  	float ca_noapoint5percent[MSA_tempcount];  
	float ca_noa1percent[MSA_tempcount];  		float ca_noa2percent[MSA_tempcount];  
	float ca_noa4percent[MSA_tempcount]; 		float ca_noa8percent[MSA_tempcount]; 
	int num_swap=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;j=0;k=0;
		//printf("\n\n\nTemplate is:%s",MSA_tempnames[i]);

	   	for(j=0,k=0;	j<MSA_templatelen[0],k<MSA_templatelen[i];	j++,k++)
	       {
			if(  (MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][k]!='-')  )
			{
				MSA_seed_residue_aligned_positions[0][j]=j;
				MSA_temphit_residue_aligned_positions[i][k]=k;
				//printf("\nSeed: %3d,Hit: %3d, Seed:%c,Hit:%c\t",MSA_seed_residue_aligned_positions[0][j],
				//MSA_temphit_residue_aligned_positions[i][k],MSA_templatearray[0][j],
				//MSA_templatearray[i][k]);
				count++;
			}
			//printf("\n========>At %3d,Seed:%c,Hit:%c\t",MSA_seed_residue_aligned_positions[i][j],
			//MSA_templatearray[0][j],MSA_templatearray[i][j]);
			num_swap=count;
			MSA_seed_aligned_residues[i]=num_swap;
   		}
		printf("\n\tTemplate %s has %d aligned residues",MSA_tempnames[i],MSA_seed_aligned_residues[i]);
	        //printf("\n__________________________________________");
	}
        printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n\n");







	int MSA_PDB_seed_residue_aligned_positions[MSA_tempcount][MSA_targetlen];
	int MSA_PDB_temphit_residue_aligned_positions[MSA_tempcount][MSA_targetlen];


	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_templatelen[i];j++)
		{
			MSA_PDB_seed_residue_aligned_positions[i][j]=-1;
			MSA_PDB_temphit_residue_aligned_positions[i][j]=-1;
		}
	}


	//for(i=0;i<MSA_tempcount;i++)
	//printf("\nTEMPLATE:%s LENGTH %d SEQUENCE: %s",MSA_tempnames[i],MSA_templatelen[i],MSA_templatearray[i]);	
	//printf("\n");
	//printf("\n    TARGET HAS LENGTH %d SEQUENCE: %s",MSA_targetlen,MSA_targetarray);
	//printf("\n");

	int temphit_smaller_cacount[MSA_tempcount];
	float INI_CA_RMS[MSA_tempcount];
	float INI_HIT_HIT_CA_RMS[MSA_tempcount][MSA_tempcount];		//Needed Later in program modules towards end
	int INI_HIT_HIT_ca_GDT_residues[MSA_tempcount][MSA_tempcount];	//Needed Later in program modules towards end
	float HIT_HIT_TM_Score[MSA_tempcount][MSA_tempcount];		

	int lm=0; int lt=0;
	swap1=0;
	int matmpdb_aapos_count=0;
	k2=0;
	x1=0;
	int tatmpdb_aapos_count=0;
	int lm1=0; int lt1=0;
	int  smaller_cacount = 0;
	float DELX=0;float DELY=0;float DELZ=0;
	float INIDELX=0;float INIDELY=0;float INIDELZ=0;
	float swapx=0;float swapy=0;float swapz=0;


	int optimax=0;
	double dr=0;
	double SX1x=0;double SY1x=0;double SZ1x=0;double SX0x=0;double SY0x=0;double SZ0x=0;	
	float smytyx=0;float smytzx=0;float smztyx=0;float smztzx=0;
	float rotanglex=0; float costhex=0;float sinthex=0;float shiftzx=0;float shiftyx=0;float rmsx=0;
	double SX1y=0;double SY1y=0;double SZ1y=0;double SX0y=0;double SY0y=0;double SZ0y=0;
	float smxtxy=0;float smxtzy=0;float smztxy=0;float smztzy=0;
	float rotangley=0;float costhey=0;float sinthey=0;float shiftxy=0;float shiftzy=0;float rmsy=0;
	double SX1z=0;double SY1z=0;double SZ1z=0;double SX0z=0;double SY0z=0;double SZ0z=0;
	float smxtxz=0;float smxtyz=0;float smytxz=0;float smytyz=0;
	float rotanglez=0; float costhez=0;float sinthez=0;float shiftxz=0;float shiftyz=0;float rmsz=0;
	int n=1;float cycrms=0; 
	float best_temp_CA_RMS[MSA_tempcount];

	int noapoint25=0;int noapoint5=0;int noa1=0;int noa2=0; int noa4=0;int noa8=0;
	fswap=0; a1=0; b1=0; 
	int temphit_ca_GDT_residues[MSA_tempcount];float temphit_ca_GDT_TS[MSA_tempcount];

	float INI_ca_noapoint25percent[MSA_tempcount];float INI_ca_noapoint5percent[MSA_tempcount];
	float INI_ca_noa1percent[MSA_tempcount];float INI_ca_noa2percent[MSA_tempcount];
	float INI_ca_noa4percent[MSA_tempcount];float INI_ca_noa8percent[MSA_tempcount];
	float INI_temphit_ca_GDT_TS[MSA_tempcount];
	int INI_temphit_ca_GDT_residues[MSA_tempcount];



	float seed_hit_TM_Score[MSA_tempcount];		//TM_Score variable for MSA_tempcount
	float d0_for_TM=0;				//do variable dinominator for TM-Score calculation
	float tm_swap=0;float tm_swap1=0;float tm_swap2=0;

	float fswap2=0;float fswap3=0;
	float fsum1,fsum2=0; fsum1=fsum2=0;
	int sum1,sum2=0;sum1=sum2=0;

	float fswap5=0;
	float seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_tempcount]; 
	int seed_temp_temp_hit_ave_dist_lt_threshold_analysis_count[MSA_tempcount]; 

	float seed_hit_mean_model_INI_CA_RMS[MSA_tempcount];
	float seed_hit_mean_model_ca_GDT_TS[MSA_tempcount];
	int seed_hit_mean_model_ca_GDT_residues[MSA_tempcount];
	float seed_hit_mean_model_TM_Score[MSA_tempcount];
	float seed_hit_mean_model_ca_noapoint25percent[MSA_tempcount];
	float seed_hit_mean_model_ca_noapoint5percent[MSA_tempcount];
	float seed_hit_mean_model_ca_noa1percent[MSA_tempcount];
	float seed_hit_mean_model_ca_noa2percent[MSA_tempcount];
	float seed_hit_mean_model_ca_noa4percent[MSA_tempcount];
	float seed_hit_mean_model_ca_noa8percent[MSA_tempcount];
	float seed_hit_mean_model_ca_avg_distance[MSA_tempcount];
	float distance3=0;
	float seed_hit_opti_TM_Score[MSA_tempcount];

	FILE *fp;
	for(j=0;j<MSA_tempcount;j++)
	{
		fp = fopen (MSA_pdbfiles[j],"r");
		if (fp == NULL)
		{
			printf("\nFile %s does not exist in PWD",MSA_pdbfiles[j]);
			exit(0);
			fp=0;
		}
		else
		{
			printf("\nPDBFILE %3d is %6s",j,MSA_pdbfiles[j]);
			continue;
		}
	}





	printf("\n");matm = mpdbToArray2(MSA_pdbfiles[0]);
	for(i=0;i<MSA_tempcount;i++)   	
	{
		tatm = mpdbToArray2(MSA_pdbfiles[i]);
		printf("\n Seed: %s \t Hit: %s",MSA_pdbfiles[0],MSA_pdbfiles[i]);
		//Actual MSA based Parsing Starts for the Seed and template PDB residues
		lm=arraylength(matm);lt=arraylength(tatm);
		printf("\tLM:%4d,LT:%4d\tAligned_Residues:%4d",lm,lt,MSA_seed_aligned_residues[i]);
		printf("\n");
		
		x1=0;
		int MSA_seed_PDB_aligned_aa[MSA_seed_aligned_residues[i]];
		int MSA_temphit_PDB_aligned_aa[MSA_seed_aligned_residues[i]];
		j=0;k=0;k1=0;k2=0;
		while(  (j<MSA_templatelen[0]) && (k<MSA_templatelen[i]) )
		{
			if(  (MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][k]!='-')  )
			{
				MSA_PDB_seed_residue_aligned_positions[i][j]=k1;
				MSA_PDB_temphit_residue_aligned_positions[i][k]=k2;
				//printf("\nAt Seed: %3d,Hit: %3d, Seed:%c,Hit:%c\t",
				//MSA_PDB_seed_residue_aligned_positions[i][j],
				//MSA_PDB_temphit_residue_aligned_positions[i][k],MSA_templatearray[0][j],
				//MSA_templatearray[i][k]);
				//printf("\t\tBoth_Residue_K1:%d,K2:%d",k1,k2);
	
				MSA_seed_PDB_aligned_aa[x1]=k1;
				MSA_temphit_PDB_aligned_aa[x1]=k2;
				j++;k++;k1++;k2++;x1++;
			}
			if(  (MSA_templatearray[0][j]=='-') && (MSA_templatearray[i][k]=='-')  )
			{
				MSA_PDB_seed_residue_aligned_positions[i][j]=-1;
				MSA_PDB_temphit_residue_aligned_positions[i][k]=-1;
				//printf("\n======>===>=====>>===>>Seed_Gap_Hit_Residue_K1:%d,K2:%d",k1,k2);
				j++;k++;
			}
			if(  (MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][k]=='-')  )
			{
				MSA_PDB_seed_residue_aligned_positions[i][j]=j;
				MSA_PDB_temphit_residue_aligned_positions[i][k]=-1;
				//printf("\n======>>===>========>>>Seed_Residue_Hit_Gap_K1:%d,K2:%d",k1,k2);
				j++;k++;k1++;
			}
	
			if(  (MSA_templatearray[0][j]=='-') && (MSA_templatearray[i][k]!='-')  )
			{
				MSA_PDB_seed_residue_aligned_positions[i][j]=-1;
				MSA_PDB_temphit_residue_aligned_positions[i][k]=k;
				//printf("\n=======>>===>====>>===>Both gap_K1:%d,K2:%d",k1,k2);
				j++;k++;k2++;
			}
		}
		
	


		//Don't change next 4 lines. They are same for temhit too. Don't copy them additionally for template hit.
		//for(j=0;j<MSA_seed_aligned_residues[i];j++)
		//printf("\nSeed_Residue_K1:%d,Template Residue K2:%d",MSA_seed_PDB_aligned_aa[j],
		//MSA_temphit_PDB_aligned_aa[j]);

		//_______________________________________________________________________________________________________
		//Copy only the desired MSA based residue positions in a new array

		//for(j=0;j<MSA_seed_aligned_residues[i];j++)
		//printf("\nSeed_Residue_K1:%d,Template Residue K2:%d",MSA_seed_PDB_aligned_aa[j],
		//MSA_temphit_PDB_aligned_aa[j]);

		//MSA_Based_PDB_File_Parsing_Starts_for Model & Template Hit PDB Files
		//For Model/Seed Template PDB
		int MSA_seed_PDB_aligned_aa_pos[MSA_seed_aligned_residues[i]];int count9=0;
		swap1=matm[0].pos;
		//printf("\nSwap1:%d",swap1);count=0;
		for(j=0;j<lm;j++)
		{
			if (j<1) 
			{
				//printf("\naaCount9:%d\t%d",count9,matm[j].pos);
				count++;count9++;
				swap1=matm[j].pos;
			}
			else if( (matm[j].pos!=swap1) && (j>1))
			{
				//printf("\nCount9:%d\t%d",count9,matm[j].pos);
				count++;count9++;
				swap1=matm[j].pos;
			}
			else				
			swap1=matm[j].pos;
		}
		matmpdb_aapos_count=count9;



		//printf("\nTotal %d residues are there in seed %s template",matmpdb_aapos_count,MSA_pdbfiles[0]);
		int matmpdb_aapos[matmpdb_aapos_count];count=0;
		k=0;
		k1=0;swap1=matm[0].pos;k2=0;int MSA_seed_PDB_aligned_aa_pos1[MSA_seed_aligned_residues[i]];count9=0;
		for(j=0;j<lm;j++)
		{
			if (j<1) 
			{
				matmpdb_aapos[k]=matm[j].pos;		    
				//if(MSA_seed_PDB_aligned_aa[k1]==count9)   
				MSA_seed_PDB_aligned_aa_pos[k1]=matm[j].pos;
				//printf("\n>seed:%s seed_Count9:%d\tmatmpdb_aapos[k]:%d, POS:%d",MSA_pdbfiles[0], 
				//count9,matmpdb_aapos[k],MSA_seed_PDB_aligned_aa_pos[k1]);
				MSA_seed_PDB_aligned_aa_pos1[k2]=MSA_seed_PDB_aligned_aa_pos[k1];
				k++;k1++;count++;k2++;count9++;
				swap1=matm[j].pos;
			}
			else if( (matm[j].pos!=swap1) && (j>1))
			{
				matmpdb_aapos[k]=matm[j].pos;
				//printf("\nSeed:%s Seed_Count9:%d\tmatm_aapos:%d",MSA_pdbfiles[0],count9,matmpdb_aapos[k]);
				if(MSA_seed_PDB_aligned_aa[k1]==count)
				{
					MSA_seed_PDB_aligned_aa_pos[k1]=matmpdb_aapos[k];
					//printf("\n>Seed:%s Seed_Count:%d\tmatmpdb_aapos[k]:%d, POS:%d",MSA_pdbfiles[0], 
					//count,matmpdb_aapos[k],MSA_seed_PDB_aligned_aa_pos[k1]);
					MSA_seed_PDB_aligned_aa_pos1[k2]=MSA_seed_PDB_aligned_aa_pos[k1];
					k1++;k2++;
				}
				count++;count9++;
				k++;
				swap1=matm[j].pos;
			}
			else				
			swap1=matm[j].pos;
		}
		
		k=0;k1=0;j=0;count=0;swap1=0;


		//For Template Hit PDB
		int MSA_temphit_PDB_aligned_aa_pos[MSA_seed_aligned_residues[i]];count9=0;
		int MSA_temphit_PDB_aligned_aa_pos1[MSA_seed_aligned_residues[i]];
		swap1=tatm[0].pos;
		//printf("\nSwap1:%d",swap1);count=0;
		for(j=0;j<lt;j++)
		{
			if (j<1) 
			{
				//printf("\naaCount9:%d\t%d",count9,tatm[j].pos);
				count++;count9++;
				swap1=tatm[j].pos;
			}
			else if( (tatm[j].pos!=swap1) && (j>1))
			{
				//printf("\nCount9:%d\t%d",count9,tatm[j].pos);
				count++;count9++;
				swap1=tatm[j].pos;
			}
			else				
			swap1=tatm[j].pos;
		}
		tatmpdb_aapos_count=count9;
		//printf("\nTotal %d residues are there in hit %s template",tatmpdb_aapos_count,MSA_pdbfiles[0]);
		int tatmpdb_aapos[tatmpdb_aapos_count];count=0;
		k=0;
		k1=0;swap1=tatm[0].pos;k2=0;
		count9=0;
		for(j=0;j<lt;j++)
		{
			if (j<1) 
			{
				tatmpdb_aapos[k]=tatm[j].pos;		    
				//if(MSA_temphit_PDB_aligned_aa[k1]==count9)  
				MSA_temphit_PDB_aligned_aa_pos[k1]=tatm[j].pos;
				//printf("\n>temphit:%s temphit_Count9:%d\ttatmpdb_aapos[k]:%d, POS:%d",MSA_pdbfiles[0], 
				//count9,tatmpdb_aapos[k],MSA_temphit_PDB_aligned_aa_pos[k1]);
				MSA_temphit_PDB_aligned_aa_pos1[k2]=MSA_temphit_PDB_aligned_aa_pos[k1];
				k++;k1++;count++;k2++;count9++;
				swap1=tatm[j].pos;
			}
			else if( (tatm[j].pos!=swap1) && (j>1))
			{
				tatmpdb_aapos[k]=tatm[j].pos;
				//printf("\n>Hit:%s Hit_Count9:%d\ttatm_aapos:%d",MSA_pdbfiles[0],count9,tatmpdb_aapos[k]);
				if(MSA_temphit_PDB_aligned_aa[k1]==count)
				{
					MSA_temphit_PDB_aligned_aa_pos[k1]=tatmpdb_aapos[k];
					//printf("\n>Hit:%s Hit_Count:%d\ttatmpdb_aapos[k]:%d, POS:%d",MSA_pdbfiles[0], 
					//count,tatmpdb_aapos[k],MSA_temphit_PDB_aligned_aa_pos[k1]);
					MSA_temphit_PDB_aligned_aa_pos1[k2]=MSA_temphit_PDB_aligned_aa_pos[k1];
					k1++;k2++;
				}
				count++;count9++;
				k++;
				swap1=tatm[j].pos;
			}
			else				
			swap1=tatm[j].pos;
		}
		
		k=0;k1=0;j=0;count=0;swap1=0;
		//for(j=0;j<MSA_seed_aligned_residues[i];j++)
		//printf("\nMSA_temphit_PDB_aligned_aa_pos1[%d]:%d", j,MSA_temphit_PDB_aligned_aa_pos1[j]);

		//for(j=0;j<MSA_seed_aligned_residues[i];j++)
		//printf("\nMSA_seed_PDB_aligned_aa_pos[%3d]:%d,MSA_temphit_PDB_aligned_aa_pos1[%3d]:%d",j, 
		//MSA_seed_PDB_aligned_aa_pos1[j],j,MSA_temphit_PDB_aligned_aa_pos1[j]);
		//MSA_seed_PDB_aligned_aa_pos1 is same as MSA_seed_PDB_aligned_aa_pos. Both are correct.


		//_____________________________________________________________________________________________________
		//Copy only the desired MSA based residue positions in a new array
		//Copy the coordinate info for the MSA aligned residues from the Seed PDB file on basis 
		// of matmpdb_aapos_count,matmpdb_aapos[j],MSA_seed_aligned_residues[i],
                //                  MSA_PDB_seed_residue_aligned_positions[i][j]		
		// And then do it the same way for the template hit PDB file.
		printf("\n\n");
		count=0;k=0;j=0;
		printf("\nMSA_seed_aligned_residues[i]:%d",MSA_seed_aligned_residues[i]);
		for(j=0;j<MSA_seed_aligned_residues[i];j++)
		{
			k=0;
			while(k<lm)
			{
				if(MSA_seed_PDB_aligned_aa_pos1[j]==matm[k].pos)
				{
					//printf("\tCount:%3d\tmatm[k].pos=%3d   ",count,matm[k].pos);
					count++;
				}
				k++;
			}
		}
		//printf("\nCount:%d",count);


		lm1=count;
		printf("\nLM1:%d",lm1);

		float matmx[lm1];float matmy[lm1];float matmz[lm1];int matm_pos[lm1];
		char matm_mol[lm1][100];
		float swap_xc[lm1];float swap_yc[lm1];float swap_zc[lm1];
		count=0;k=0;j=0;
		for(j=0;j<MSA_seed_aligned_residues[i];j++)
		{
			k=0;
			while(k<lm)
			{
				if(MSA_seed_PDB_aligned_aa_pos1[j]==matm[k].pos)
				{
					matmx[count]=matm[k].xc;	swap_xc[count]=matm[k].xc;
					matmy[count]=matm[k].yc;	swap_yc[count]=matm[k].yc;
					matmz[count]=matm[k].zc;	swap_zc[count]=matm[k].zc;
					matm_pos[count]=matm[k].pos;
					strcpy(matm_mol[count],matm[k].mol);
					//printf("\nCount:%3d\tmatm[k].mol=%s\t\tmatm[k].pos=%3d\t\tXC:%4.3f\tYC:%4.3f\tZC:%4.3f",					count,matm[k].mol,matm_pos[count],matm[k].xc,matm[k].yc,matm[k].zc);
					//printf("\nCount:%3d\tmatm[k].mol=%s\t\tmatm[k].pos=%3d\t\tXC:%4.3f\tYC:%4.3f\tZC:%4.3f",					count,matm_mol[count],matm[k].pos,swap_xc[count],swap_yc[count],swap_zc[count]);
					count++;
				}
				k++;
			}
		}




		//Now, MSA based Coordinate parsing starts for template hit
		//printf("\n\n");
		count=0;k=0;j=0;
		for(j=0;j<MSA_seed_aligned_residues[i];j++)
		{
			k=0;
			while(k<lt)
			{
				if(MSA_temphit_PDB_aligned_aa_pos1[j]==tatm[k].pos)
				{
					//printf("\tCount:%3d\ttatm[k].pos=%3d   ",count,tatm[k].pos);
					count++;
				}
				k++;
			}
		}
		//printf("\nCount:%d",count);

		lt1=count;
		float tatmx[lt1];float tatmy[lt1];float tatmz[lt1];int tatm_pos[lt1];
		char tatm_mol[lt1][100];
		count=0;k=0;j=0;
		for(j=0;j<MSA_seed_aligned_residues[i];j++)
		{
			k=0;
			while(k<lt)
			{
				if(MSA_temphit_PDB_aligned_aa_pos1[j]==tatm[k].pos)
				{
					tatmx[count]=tatm[k].xc;
					tatmy[count]=tatm[k].yc;
					tatmz[count]=tatm[k].zc;
					tatm_pos[count]=tatm[k].pos;
					strcpy(tatm_mol[count],tatm[k].mol);
					//printf("\tHit:%s\tCount:%3d\ttatm_mol[k]=%s\ttatm[k].pos=%3d\t\tXC:%4.3f\tYC:%4.3f\tZC:%4.3f",				MSA_pdbfiles[i],count,tatm_mol[count],tatm_pos[count],tatmx[count],
					//tatmy[count],tatmz[count]);
					count++;
				}
				k++;
			}
		}



		//Now find RMSD using data  tatmx[lt1],tatmy[lt1],tatmz[lt1],tatm_mol[lt1],tatm_pos[lt1]
		//			    matmx[lm1],matmy[lm1],matmz[lm1],matm_mol[lm1],matm_pos[lm1] 
		//                          swap_xc[lm1],swap_yc[lm1],swap_zc[lm1],MSA_seed_aligned_residues[i]
		float matmcx[lm1],matmcy[lm1],matmcz[lm1];
		for(j=0;j<lm1;j++)
		{
			matmcx[j]=matmx[j];
			matmcy[j]=matmy[j];
			matmcz[j]=matmz[j];
		}
		//matm is seed and tatm is template hit
		printf("\nAs per MSA file, following is the detail for the seed and hit template as per their PDB files");
		printf("\n\nTotal Number of atoms in MSA_Based_Parsed_MATM_SEED_TEMPLATE %s PDB file is:\t\t%d",
		MSA_pdbfiles[0],lm1);
		printf("\nTotal Number of atoms in MSA_Based_Parsed_TATM_Template_HIT %s PDB file is:\t\t%d",
		MSA_pdbfiles[i],lt1);
	

		//for(j=0;j<MSA_seed_aligned_residues[i];j++)
		//printf("\n\t\tSeed_Residue_K1:%d,Template Residue K2:%d",MSA_seed_PDB_aligned_aa[j],
		//MSA_temphit_PDB_aligned_aa[j]);
		//printf("\n=========================================================================================");
		//for(j=0;j<MSA_seed_aligned_residues[i];j++)
		//printf("\n\t\tMSA_seed_PDB_aligned_aa_pos1[k1]:%d,MSA_temphit_PDB_aligned_aa_pos1[k1]:%d", 
		//MSA_seed_PDB_aligned_aa_pos1[j],MSA_temphit_PDB_aligned_aa_pos1[j]);
	
		j=0;k=0;
		float matmca_xc[MSA_seed_aligned_residues[i]];float matmca_yc[MSA_seed_aligned_residues[i]];
		float matmca_zc[MSA_seed_aligned_residues[i]];float tatmca_xc[MSA_seed_aligned_residues[i]];
		float tatmca_yc[MSA_seed_aligned_residues[i]];float tatmca_zc[MSA_seed_aligned_residues[i]];	
		//printf("\n\n");
		//for(j=0;j<lm1;j++)
		//printf("\nj:%3d\tmatm_mol=%s\t\tmatm_pos:%d\tXC:%4.3f\tYC:%4.3f\tZC:%4.3f",j,matm_mol[j],matm_pos[j],
		//matmx[j],matmy[j],matmz[j]);
		//for(j=0;j<lt1;j++)
		//printf("\nj:%3d\ttatm[j].mol=%s\t\ttatm_pos:%d\tXC:%4.3f\tYC:%4.3f\tZC:%4.3f",j,tatm_mol[j],tatm_pos[j],
		//tatmx[j],tatmy[j],tatmz[j]);


		//printf("\n\n");
	


		for(j=0;j<lm1;j++)
		{
		    if(strstr(matm_mol[j],"CA")!=0)
		    {
		       matmca_xc[k]=matmx[j];
		       matmca_yc[k]=matmy[j];
		       matmca_zc[k]=matmz[j];
		      //printf("\nmatm_K:%3d\t%s\t%d\t%.3f\t%.3f\t%.3f",k,matm_mol[j],matm_pos[j],matmca_xc[k],matmca_yc[k],matmca_zc[k]);
		      k++;
		    }
		}


		j=0;k=0;
		//for(j=0;j<lt1;j++)
		//printf("\nj:%3d\ttatm[j].mol=%s\t\ttatm_pos:%d\tXC:%4.3f\tYC:%4.3f\tZC:%4.3f",j,tatm_mol[j],tatm_pos[j],
		//tatmx[j],tatmy[j],tatmz[j]);
		//printf("\n\n");
	
		for(j=0;j<lt1;j++)
		{
		  if(strstr(tatm_mol[j],"CA")!=0)
		  {
		     tatmca_xc[k]=tatmx[j];
		     tatmca_yc[k]=tatmy[j];
		     tatmca_zc[k]=tatmz[j];
		     //printf("\ntatm_K:%3d\t%s\t%d\t%.3f\t%.3f\t%.3f",k,tatm_mol[j],tatm_pos[j],tatmca_xc[k],tatmca_yc[k],tatmca_zc[k]);
		     k++;
		   }
		}


		k=0;
		//Finding RMSD of aligned residues of all template hits against the seed residues.
		//Copy the Y and Z coordinates of the PDB files the same way to go further for the RMSD Calculation
		//Initial RMS finding before Optimization of Rotational Matrics with angle findings and shifts of coodinates
	  	smaller_cacount = MSA_seed_aligned_residues[i];	//Both are equal
		printf("\t\tMSA_Based_Parsed One to One Residue Count for Model and Template:%d\t",smaller_cacount);
		//for(j=0;j<smaller_cacount;j++)
		//printf("\nJ:%3d\tMATMX:%4.3f\tMATMY:%4.3f\tMATMZ:%4.3f|TATMX:%4.3f\tTATMY:%4.3f\tTATMZ:%4.3f\t\t",j, 
		//matmca_xc[j], matmca_yc[j],matmca_zc[j],tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
		
	
		DELX=0;DELY=0;DELZ=0;
		INIDELX=0;INIDELY=0;INIDELZ=0;
	
		//INITIAL RMSD CALCULATION FOR CALPHA COORDINATES
		INIDELX=0;INIDELY=0;INIDELZ=0;
		for (j=0;j<smaller_cacount;j++)
		{
			INIDELX = INIDELX + pow((matmca_xc[j] - tatmca_xc[j]),2);
			INIDELY = INIDELY + pow((matmca_yc[j] - tatmca_yc[j]),2);
			INIDELZ = INIDELZ + pow((matmca_zc[j] - tatmca_zc[j]),2);
			//printf("\nINIDELX:%f,INIDELY:%f,INIDELZ:%f",INIDELX,INIDELY,INIDELZ);
		}
	
		INI_CA_RMS[i]=(INIDELX+INIDELY+INIDELZ)/smaller_cacount;
		INI_CA_RMS[i]=pow(INI_CA_RMS[i],0.5);
		INIDELX=sqrt(INIDELX/smaller_cacount);
		INIDELY=sqrt(INIDELY/smaller_cacount);
		INIDELZ=sqrt(INIDELZ/smaller_cacount);
		printf("\n\n\nINITIAL RMSD DETAIL FOR CALPHA COORDINATES IS");
		printf("\nDELX=%0.5f\tDELY=%0.5f\tDELZ=%0.5f\tINITIAL CA RMSD=%0.5f, CA_COUNT:%d\n",INIDELX,INIDELY, 
		INIDELZ,INI_CA_RMS[i],MSA_seed_aligned_residues[i]);
	




		//GDT Calculation for Calpha atoms at 0.25,0.5,1,2,4,8A' distance deviations
		printf("\n");
		//matmca_xc[j], tatmca_xc[k],temphit_smaller_cacount[i]
		noapoint25=0;noapoint5=0;noa1=0;noa2=0;noa4=0;noa8=0;
		k=0;
		float INI_ca_distance[smaller_cacount];
		fswap=0; 
		a1=0; b1=0; k=0;
		d0_for_TM= 1.24 * pow((MSA_actual_templatelen[0]-15), 0.33333333333333333) -1.8;
		tm_swap=0;tm_swap1=0;tm_swap2=0;
		
		for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
		{		
			DELX = pow((matmca_xc[j] - tatmca_xc[k]),2);
			DELY = pow((matmca_yc[j] - tatmca_yc[k]),2);
			DELZ = pow((matmca_zc[j] - tatmca_zc[k]),2);
		
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[k],tatmca_yc[k],tatmca_zc[k]);
			fswap=DELX+DELY+DELZ;
			fswap=pow(fswap,0.5);
			INI_ca_distance[k]=fswap;

			//TM-Score calculation
			tm_swap1=1 + pow((INI_ca_distance[k]/d0_for_TM),2);
			tm_swap2=1/tm_swap1;
			tm_swap= tm_swap + tm_swap2;	

			//printf("\ti+1:%3d,INI_CA_DISTANCE:%f",i,INI_ca_distance[k]);
		
			if(INI_ca_distance[k]<=0.25)
			{
				noapoint25++;
			}
			else if( (INI_ca_distance[k]<=0.5) && (INI_ca_distance[k]>0.25) )
			{
				noapoint5++;
			}
			else if( (INI_ca_distance[k]<=1) && (INI_ca_distance[k]>0.5))
			{
				noa1++;
			}
			else if((INI_ca_distance[k]<=2) && (INI_ca_distance[k]>1))
			{
				noa2++;
			}
			else if((INI_ca_distance[k]<=4) && (INI_ca_distance[k]>2))
			{
				noa4++;
			}
			else if((INI_ca_distance[k]<=8) && (INI_ca_distance[k]>4))
			{
				noa8++;
			}
			//printf("\n========>K:%d",k);
		}	
		
		INI_temphit_ca_GDT_residues[i]=noapoint25+noapoint5+noa1+noa2+noa4+noa8;
		seed_hit_TM_Score[i]=tm_swap/MSA_actual_templatelen[0];
		
		
		a1=noapoint25;
		b1=smaller_cacount;
		INI_ca_noapoint25percent[i]=(a1/b1) * 100;
		
		a1=noapoint25 + noapoint5;
		b1=smaller_cacount;
		INI_ca_noapoint5percent[i]=(a1/b1)*100;
	
		a1=noapoint25 + noapoint5 + noa1;
		b1=smaller_cacount;
		INI_ca_noa1percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2;
		b1=smaller_cacount;
		INI_ca_noa2percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2 + noa4;
		b1=smaller_cacount;
		INI_ca_noa4percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2 + noa4 + noa8;
		b1=smaller_cacount;
		INI_ca_noa8percent[i]=(a1/b1) * 100;

		INI_temphit_ca_GDT_TS[i]=(INI_ca_noa1percent[i] + INI_ca_noa2percent[i] + INI_ca_noa4percent[i] + 			INI_ca_noa8percent[i])/4;
		//printf("\nNOA0.25percent:%4.4f,NOA0.5percent:%4.4f,NOA1percent:%4.4f,noa2percent:%4.4f,noa4percent:%4.4f, noa8percent:%4.4f",INI_ca_noapoint25percent[i],INI_ca_noapoint5percent[i],INI_ca_noa1percent[i], INI_ca_noa2percent[i], INI_ca_noa4percent[i],INI_ca_noa8percent[i]);

		temphit_ca_GDT_TS[i]=(INI_ca_noa1percent[i]+INI_ca_noa2percent[i] + INI_ca_noa4percent[i] + INI_ca_noa8percent[i])/4;
		//printf("\n\n\nAll Residues' Calpha temphit_ca_GDT_TS[i]=%5.4f, ca_GDT_Residues[i]:%d\tseed_hit_TM_Score:%f",INI_temphit_ca_GDT_TS[i],INI_temphit_ca_GDT_residues[i],seed_hit_TM_Score[i]);
		//___________________________________________________________________________________________________	




























		//Calculation of seed_hit average model's deviation from the seed template
		float INI_ca_distance1[smaller_cacount];
		noapoint25=0;noapoint5=0;noa1=0;noa2=0;noa4=0;noa8=0;
		tm_swap=0;tm_swap1=0;tm_swap2=0;fswap=0;

		INIDELX=0;INIDELY=0;INIDELZ=0;
		for (j=0;j<smaller_cacount;j++)
		{
			INIDELX = INIDELX + pow(  ( matmca_xc[j] - (tatmca_xc[j]+matmca_xc[j])/2),2);
			INIDELY = INIDELY + pow(  ( matmca_yc[j] - (tatmca_yc[j]+matmca_yc[j])/2),2);
			INIDELZ = INIDELZ + pow(  ( matmca_zc[j] - (tatmca_zc[j]+matmca_zc[j])/2),2);
			//printf("\nINIDELX:%f,INIDELY:%f,INIDELZ:%f",INIDELX,INIDELY,INIDELZ);
		}
		seed_hit_mean_model_INI_CA_RMS[i]=(INIDELX+INIDELY+INIDELZ)/smaller_cacount;

		for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
		{		
			DELX = pow(  ( matmca_xc[j] - (tatmca_xc[j]+matmca_xc[j])/2),2);
			DELY = pow(  ( matmca_yc[j] - (tatmca_yc[j]+matmca_yc[j])/2),2);
			DELZ = pow(  ( matmca_zc[j] - (tatmca_zc[j]+matmca_zc[j])/2),2);
		
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[k],tatmca_yc[k],tatmca_zc[k]);
			fswap=DELX+DELY+DELZ;
			fswap=pow(fswap,0.5);
			INI_ca_distance1[k]=fswap;

			distance3=distance3 + INI_ca_distance1[k];

			//TM-Score calculation
			tm_swap1=1 + pow((INI_ca_distance1[k]/d0_for_TM),2);
			tm_swap2=1/tm_swap1;
			tm_swap= tm_swap + tm_swap2;	

			//printf("\ti+1:%3d,INI_CA_DISTANCE:%f",i,INI_ca_distance[k]);
		
			if(INI_ca_distance1[k]<=0.25)
			{
				noapoint25++;
			}
			else if( (INI_ca_distance1[k]<=0.5) && (INI_ca_distance1[k]>0.25) )
			{
				noapoint5++;
			}
			else if( (INI_ca_distance1[k]<=1) && (INI_ca_distance1[k]>0.5))
			{
				noa1++;
			}
			else if((INI_ca_distance1[k]<=2) && (INI_ca_distance1[k]>1))
			{
				noa2++;
			}
			else if((INI_ca_distance1[k]<=4) && (INI_ca_distance1[k]>2))
			{
				noa4++;
			}
			else if((INI_ca_distance1[k]<=8) && (INI_ca_distance1[k]>4))
			{
				noa8++;
			}
			//printf("\n========>K:%d",k);
		}	
		

		seed_hit_mean_model_ca_GDT_residues[i]=noapoint25+noapoint5+noa1+noa2+noa4+noa8;
		seed_hit_mean_model_TM_Score[i]=tm_swap/MSA_actual_templatelen[0];


		a1=noapoint25;
		b1=smaller_cacount;
		seed_hit_mean_model_ca_noapoint25percent[i]=(a1/b1) * 100;
		
		a1=noapoint25 + noapoint5;
		b1=smaller_cacount;
		seed_hit_mean_model_ca_noapoint5percent[i]=(a1/b1)*100;
	
		a1=noapoint25 + noapoint5 + noa1;
		b1=smaller_cacount;
		seed_hit_mean_model_ca_noa1percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2;
		b1=smaller_cacount;
		seed_hit_mean_model_ca_noa2percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2 + noa4;
		b1=smaller_cacount;
		seed_hit_mean_model_ca_noa4percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2 + noa4 + noa8;
		b1=smaller_cacount;
		seed_hit_mean_model_ca_noa8percent[i]=(a1/b1) * 100;

		seed_hit_mean_model_ca_GDT_TS[i]=(seed_hit_mean_model_ca_noa1percent[i] + 
						  seed_hit_mean_model_ca_noa2percent[i] + 
						  seed_hit_mean_model_ca_noa4percent[i] + 
						  seed_hit_mean_model_ca_noa8percent[i])/4;

		seed_hit_mean_model_ca_avg_distance[i]=distance3/smaller_cacount;
		distance3=0;
		printf("\nTemp:%s sh_mean_model_ca_avg_distance:%6.3f,RMS:%6.3f,TM_Score:%6.3f,GDT_TS:%6.3f",MSA_tempnames[i],seed_hit_mean_model_ca_avg_distance[i],seed_hit_mean_model_INI_CA_RMS[i], seed_hit_mean_model_TM_Score[i],seed_hit_mean_model_ca_GDT_TS[i]);






















		printf("\n\n\n\nAfter the Initial RMSD finding, now the Optimization starts.....................");
		printf("\nNow for Iterative RMSD, we will consider the smaller length of Model & Template.");
		printf("\nThus, the smaller length in template & Model is \t%d",smaller_cacount);
		printf("\nScript is Self Adjusting Optimization Parameters based on the MSA_based parsed segment length");


		//	lm1  =>  matm_mol[j],matm_pos[j],matmx[j],matmy[j],matmz[j],
		//	MSA_seed_aligned_residues[i],  =>  matmca_xc[k],matmca_yc[k],matmca_zc[k],
		//	lt1 =>   tatm_mol[j],tatm_pos[j],tatmx[j],tatmy[j],tatmz[j],
		//	MSA_seed_aligned_residues[i]   =>  tatmca_xc[k],tatmca_yc[k],tatmca_zc[k],

		//_______________________________________________________________________________________________________
		optimax=30;
		dr=(double)(smaller_cacount);
		SX1x=0;SY1x=0;SZ1x=0;SX0x=0;SY0x=0;SZ0x=0;	
		smytyx=0;smytzx=0;smztyx=0;smztzx=0;
		rotanglex=0; costhex=0;sinthex=0;shiftzx=0;shiftyx=0;rmsx=0;
		SX1y=0;SY1y=0;SZ1y=0;SX0y=0;SY0y=0;SZ0y=0;
		smxtxy=0;smxtzy=0;smztxy=0;smztzy=0;
		rotangley=0;costhey=0;sinthey=0;shiftxy=0;shiftzy=0;rmsy=0;
		SX1z=0;SY1z=0;SZ1z=0;SX0z=0;SY0z=0;SZ0z=0;
		smxtxz=0;smxtyz=0;smytxz=0;smytyz=0;
		rotanglez=0; costhez=0;sinthez=0;shiftxz=0;shiftyz=0;rmsz=0;
		n=1;cycrms=0; 
		k=0;
		//Finding RMSD of aligned residues of all template hits against the seed residues.
		//Copy the Y and Z coordinates of the PDB files the same way to go further for the RMSD Calculation
	
		float swapca_xc[smaller_cacount];float swapca_yc[smaller_cacount];float swapca_zc[smaller_cacount];
		for(j=0;j<smaller_cacount;j++)
		{
			swapca_xc[j] = matmca_xc[j];		
			swapca_yc[j] = matmca_yc[j];
			swapca_zc[j] = matmca_zc[j];
		}




		for(n=1;n<=optimax;n++) 
		{
			//printf("\n\n\nCYCLE %d:",n);
			//printf("\n\nRotation Around X Axis:");
			//Finding Sum of Coordinates of Model after Superimposition for Rotation around X
	
			SX1x=0;SY1x=0;SZ1x=0;
			for (j=0;j<smaller_cacount;j++)
			{
				SX1x = SX1x + (double)(matmca_xc[j]);
				SY1x = SY1x + (double)(matmca_yc[j]);
				SZ1x = SZ1x + (double)(matmca_zc[j]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			} 
	
			SX0x=0;SY0x=0;SZ0x=0;j=0;
			for (j=0;j<smaller_cacount;j++)
			{
				SX0x = SX0x + (double)(tatmca_xc[j]);
				SY0x = SY0x + (double)(tatmca_yc[j]);
				SZ0x = SZ0x + (double)(tatmca_zc[j]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
	
			//Finding Products of Coordinates of Model and Template for Rotational Matrices
			smytyx=0;smytzx=0;smztyx=0;smztzx=0;
			for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
			{
				smytyx = smytyx + (double)(matmca_yc[j] * tatmca_yc[k]);
				smytzx = smytzx + (double)(matmca_yc[j] * tatmca_zc[k]);
				smztyx = smztyx + (double)(matmca_zc[j] * tatmca_yc[k]);
				smztzx = smztzx + (double)(matmca_zc[j] * tatmca_zc[k]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
	
			rotanglex=0;costhex=0;sinthex=0;shiftyx=0;shiftzx=0;		
			rotanglex=(float)(atan(((dr*(smytzx - smztyx) + (SZ1x*SY0x - SY1x*SZ0x)))/((dr*(smytyx + smztzx) - 				(SY1x*SY0x + SZ1x*SZ0x)))));
			costhex=cos((double)(rotanglex)); //costheta of the angle
			sinthex=sin((double)(rotanglex)); //sintheta of the angle
			shiftyx=(SY0x - costhex*SY1x + sinthex*SZ1x)/dr;
			shiftzx=(SZ0x - costhex*SZ1x - sinthex*SY1x)/dr;
			//printf("\nSHIFTY=%0.5f\t\tSHIFTZ=%0.5f\t\tTHETAX=%0.5f",shiftyx,shiftzx,rotanglex);	
	
			for (j=0;j<smaller_cacount;j++)
		        {
				matmca_yc[j] = swapca_yc[j] * costhex - swapca_zc[j] * sinthex + shiftyx;
				matmca_zc[j] = swapca_yc[j] * sinthex + swapca_zc[j] * costhex + shiftzx;
			}
	
			DELX=0;DELY=0;DELZ=0;cycrms=0;
			for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
			{
				DELX = DELX + pow((matmca_xc[j] - tatmca_xc[k]),2);
				DELY = DELY + pow((matmca_yc[j] - tatmca_yc[k]),2);
				DELZ = DELZ + pow((matmca_zc[j] - tatmca_zc[k]),2);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
			//for(j=0;j<smaller_cacount;j++)
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
	
			cycrms=sqrt((DELX+DELY+DELZ)/smaller_cacount);
			DELX=sqrt((DELX)/smaller_cacount);
			DELY=sqrt((DELY)/smaller_cacount);
			DELZ=sqrt((DELZ)/smaller_cacount);
		   //printf("\n========>||||||DELX=%0.5f\t\tDELY=%0.5f\t\tDELZ=%0.5f\t\tDELR=%0.5f",DELX,DELY,DELZ,cycrms);
		
			for(j=0;j<smaller_cacount;j++)
			{
				swapca_xc[j] = matmca_xc[j];		
				swapca_yc[j] = matmca_yc[j];
				swapca_zc[j] = matmca_zc[j];
	
			}
		
			//printf("\n\nRotation Around Y Axis:");
			SX1y=0;SY1y=0;SZ1y=0;
	
			for (j=0;j<smaller_cacount;j++)		
			{
				SX1y = SX1y + (double)(matmca_xc[j]);
				SY1y = SY1y + (double)(matmca_yc[j]);
				SZ1y = SZ1y + (double)(matmca_zc[j]);
	
			} 
			SX0y=0;SY0y=0;SZ0y=0;
			for (j=0;j<smaller_cacount;j++)
			{
				SX0y = SX0y + (double)(tatmca_xc[j]);
				SY0y = SY0y + (double)(tatmca_yc[j]);
				SZ0y = SZ0y + (double)(tatmca_zc[j]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
			//Finding Products of Coordinates of Model for Rotational Matrices
			smxtxy=0;smxtzy=0;smztxy=0;smztzy=0;
			for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
			{
				smxtxy = smxtxy + (double)(matmca_xc[j] * tatmca_xc[k]);
				smxtzy = smxtzy + (double)(matmca_xc[j] * tatmca_zc[k]);
				smztxy = smztxy + (double)(matmca_zc[j] * tatmca_xc[k]);
				smztzy = smztzy + (double)(matmca_zc[j] * tatmca_zc[k]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
			rotangley=0;costhey=0;sinthey=0;shiftzy=0;shiftxy=0;
			rotangley=(float)(atan(((dr*(smztxy - smxtzy) + (SX1y*SZ0y - SZ1y*SX0y)))/((dr*(smztzy + smxtxy) -			(SZ1y*SZ0y+SX1y*SX0y)))));
			costhey=cos((double)rotangley); //costheta of the angle
			sinthey=sin((double)rotangley); //sintheta of the angle
   			shiftzy=((SZ0y - costhey*SZ1y + sinthey*SX1y)/dr);
			shiftxy=((SX0y - costhey*SX1y - sinthey*SZ1y)/dr);
			//printf("\nSHIFTX=%0.5f\t\tSHIFTZ=%0.5f\t\tTHETAY=%0.5f",shiftzy,shiftxy,rotangley);	
			
			for (j=0;j<smaller_cacount;j++)
		       {
				matmca_zc[j]=swapca_zc[j] * costhey - swapca_xc[j] * sinthey+shiftzy;
				matmca_xc[j]=swapca_zc[j] * sinthey + swapca_xc[j] * costhey+shiftxy;
			}
			
			DELX=0;DELY=0;DELZ=0;cycrms=0;
			for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
			{
				DELX = DELX + pow((matmca_xc[j] - tatmca_xc[k]),2);
				DELY = DELY + pow((matmca_yc[j] - tatmca_yc[k]),2);
				DELZ = DELZ + pow((matmca_zc[j] - tatmca_zc[k]),2);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
			cycrms=sqrt((DELX+DELY+DELZ)/smaller_cacount);
	
			DELX=sqrt((DELX)/smaller_cacount);
			DELY=sqrt((DELY)/smaller_cacount);
			DELZ=sqrt((DELZ)/smaller_cacount);
			//printf("\nDELX=%0.5f\t\tDELY=%0.5f\t\tDELZ=%0.5f\t\tDELR=%0.5f",DELX,DELY,DELZ,cycrms);
		
			for (j=0;j<smaller_cacount;j++)
			{
				swapca_xc[j] = matmca_xc[j];		
				swapca_yc[j] = matmca_yc[j];
				swapca_zc[j] = matmca_zc[j];
			}
	
			//printf("\n\nRotation Around Z Axis:");
	
			SX1z=0;SY1z=0;SZ1z=0;
			for (j=0;j<smaller_cacount;j++)
			{
				SX1z = SX1z + (double)(matmca_xc[j]);
				SY1z = SY1z + (double)(matmca_yc[j]);
				SZ1z = SZ1z + (double)(matmca_zc[j]);
			} 
			
			SX0z=0;SY0z=0;SZ0z=0;
			for (j=0;j<smaller_cacount;j++)
			{
				SX0z = SX0z + (double)(tatmca_xc[j]);
				SY0z = SY0z + (double)(tatmca_yc[j]);
				SZ0z = SZ0z + (double)(tatmca_zc[j]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
		
			//Finding Products of Coordinates of Model for Rotational Matrices
			smxtxz=0;smxtyz=0;smytxz=0;smytyz=0;
			for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
			{
				smxtxz=smxtxz + (double)(swapca_xc[j] * tatmca_xc[k]);
				smxtyz=smxtyz + (double)(swapca_xc[j] * tatmca_yc[k]);
				smytxz=smytxz + (double)(swapca_yc[j] * tatmca_xc[k]);
				smytyz=smytyz + (double)(swapca_yc[j] * tatmca_yc[k]);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
			rotanglez=0;sinthez=0;costhez=0;shiftxz=0;shiftyz=0;
			rotanglez=(float)(atan(((dr*(smxtyz - smytxz) + (SY1z*SX0z - SX1z*SY0z)))/((dr*(smxtxz + smytyz) - 					  (SX1z*SX0z + SY1z*SY0z)))));
			costhez=cos((double)rotanglez); //costheta of the angle
			sinthez=sin((double)rotanglez); //sintheta of the angle
		
			shiftxz=(SX0z - costhez*SX1z + sinthez*SY1z)/dr;
			shiftyz=(SY0z - costhez*SY1z - sinthez*SX1z)/dr;
			//printf("\nSHIFTX=%0.5f\t\tSHIFTY=%0.5f\t\tTHETAZ=%0.5f",shiftxz,shiftyz,rotanglez);	
	
			for (j=0;j<smaller_cacount;j++)
			{
				matmca_xc[j] = swapca_xc[j] * costhez - swapca_yc[j] * sinthez+shiftxz;
				matmca_yc[j] = swapca_xc[j] * sinthez + swapca_yc[j] * costhez+shiftyz;
		   	}
		
			//RMS finding after every Iteration for all X, Y,Z Coordinates
			DELX=0;DELY=0;DELZ=0;cycrms=0;
			for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
			{
				DELX = DELX + pow((matmca_xc[j] - tatmca_xc[k]),2);
				DELY = DELY + pow((matmca_yc[j] - tatmca_yc[k]),2);
				DELZ = DELZ + pow((matmca_zc[j] - tatmca_zc[k]),2);
				//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			}
	
			cycrms=sqrt((DELX+DELY+DELZ)/smaller_cacount);
			DELX=sqrt((DELX)/smaller_cacount);
			DELY=sqrt((DELY)/smaller_cacount);
			DELZ=sqrt((DELZ)/smaller_cacount);
			//printf("\nDELX=%0.5f\t\tDELY=%0.5f\t\tDELZ=%0.5f\t\tDELR=%0.5f",DELX,DELY,DELZ,cycrms);
				
			for (j=0;j<smaller_cacount;j++)
			{
				swapca_xc[j] = matmca_xc[j];		
				swapca_yc[j] = matmca_yc[j];
				swapca_zc[j] = matmca_zc[j];
			}
	
	
		}
	
	

		DELX=0;DELY=0;DELZ=0;
		for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
		{	
			DELX = DELX + pow((matmca_xc[j] - tatmca_xc[k]),2);
			DELY = DELY + pow((matmca_yc[j] - tatmca_yc[k]),2);
			DELZ = DELZ + pow((matmca_zc[j] - tatmca_zc[k]),2);
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
		}
		cycrms=sqrt((DELX+DELY+DELZ)/smaller_cacount);
		DELX=sqrt(DELX/smaller_cacount);
		DELY=sqrt(DELY/smaller_cacount);
		DELZ=sqrt(DELZ/smaller_cacount);
		best_temp_CA_RMS[i]=cycrms;
		//printf("\nINITIAL MODEL TOPOLOGY DATA:\t%8.5f\t%8.5f\t%8.5f\t%8.5f",INIDELX,INIDELY,INIDELZ,INI_CA_RMS[i]);
		//printf("\nOPTIMIZED MODEL TOPOLOGY DATA:\t%8.5f\t%8.5f\t%8.5f\t%8.5f\n",DELX,DELY,DELZ,best_temp_CA_RMS[i]);






		//GDT Calculation for Calpha atoms at 0.25,0.5,1,2,4,8A' distance deviations
		printf("\n");
		//matmca_xc[j], tatmca_xc[k],temphit_smaller_cacount[i]
	
		noapoint25=0;noapoint5=0;noa1=0;noa2=0;noa4=0;noa8=0;
		k=0;
		float ca_distance[smaller_cacount];
		fswap=0;tm_swap1=0;tm_swap2=0;tm_swap=0; 
		a1=0; b1=0; k=0;
		for (j=0,k=0;	j<smaller_cacount,k<smaller_cacount;	j++,k++)
		{		
			DELX = pow((matmca_xc[j] - tatmca_xc[k]),2);
			DELY = pow((matmca_yc[j] - tatmca_yc[k]),2);
			DELZ = pow((matmca_zc[j] - tatmca_zc[k]),2);
		
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[k],tatmca_yc[k],tatmca_zc[k]);
			fswap=DELX+DELY+DELZ;
			fswap=pow(fswap,0.5);
			ca_distance[k]=fswap;
			//printf("\ti+1:%3d,DISTANCE:%f",i,ca_distance[k]);

			//TM-Score calculation
			tm_swap1=1 + pow((ca_distance[k]/d0_for_TM),2);
			tm_swap2=1/tm_swap1;
			tm_swap= tm_swap + tm_swap2;	


			if(ca_distance[k]<=0.25)
			{
				noapoint25++;
			}
			else if( (ca_distance[k]<=0.5) && (ca_distance[k]>0.25) )
			{
				noapoint5++;
			}
			else if( (ca_distance[k]<=1) && (ca_distance[k]>0.5))
			{
				noa1++;
			}
			else if((ca_distance[k]<=2) && (ca_distance[k]>1))
			{
				noa2++;
			}
			else if((ca_distance[k]<=4) && (ca_distance[k]>2))
			{
				noa4++;
			}
			else if((ca_distance[k]<=8) && (ca_distance[k]>4))
			{
				noa8++;
			}
			//printf("\n========>K:%d",k);
		}	
		
		temphit_ca_GDT_residues[i]=noapoint25+noapoint5+noa1+noa2+noa4+noa8;
		seed_hit_opti_TM_Score[i]=tm_swap/MSA_actual_templatelen[0];




		a1=noapoint25;
		b1=smaller_cacount;
		ca_noapoint25percent[i]=(a1/b1) * 100;
		
		a1=noapoint25 + noapoint5;
		b1=smaller_cacount;
		ca_noapoint5percent[i]=(a1/b1)*100;
	
		a1=noapoint25 + noapoint5 + noa1;
		b1=smaller_cacount;
		ca_noa1percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2;
		b1=smaller_cacount;
		ca_noa2percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2 + noa4;
		b1=smaller_cacount;
		ca_noa4percent[i]=(a1/b1) * 100;
	
		a1=noapoint25 + noapoint5 + noa1 + noa2 + noa4 + noa8;
		b1=smaller_cacount;
		ca_noa8percent[i]=(a1/b1) * 100;
	
		//printf("\nNOA0.25percent:%4.4f,NOA0.5percent:%4.4f,NOA1percent:%4.4f,noa2percent:%4.4f,noa4percent:%4.4f, noa8percent:%4.4f",ca_noapoint25percent[i],ca_noapoint5percent[i],ca_noa1percent[i], ca_noa2percent[i],ca_noa4percent[i],
		//ca_noa8percent[i]);

		//temphit_ca_GDT_TS[i]=(ca_noa1percent[i]+ca_noa2percent[i] + ca_noa4percent[i] + ca_noa8percent[i])/4;
		//printf("\n\n\nAll Residues' Calpha temphit_ca_GDT_TS[i]=%5.4f, ca_GDT_Residues[i]:%d",temphit_ca_GDT_TS[i], temphit_ca_GDT_residues[i]);
		//___________________________________________________________________________________________________	


		//___________________________________________________________________________________	
		//Distance Map for seed template (Considered as Model PDB)
		// Model Calpha is (matmca_xc[j],matmca_yc[j],matmca_zc[j]) 
		// && for Template it is (tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]) 
		printf("\n\n");
		j=0;DELX=0;DELY=0;DELZ=0;
		fswap2=0;fswap3=0;
		count=0;
		float seed_temp_Ca_Ca_distance_map[smaller_cacount][smaller_cacount];
		int seed_temp_ave_dist_lt_threshold_count[smaller_cacount];
		float seed_temp_ave_dist_lt_threshold[smaller_cacount]; // ave_Ca-Ca distance of ModelPDB < 5A' for each res

		for (j=0;j<smaller_cacount;j++)
		{	
			fswap2=0;fswap3=0;count=0;
			for (k=0;k<smaller_cacount;k++)	
			{
				if(j!=k)
				{
					DELX = pow((matmca_xc[j] - matmca_xc[k]),2);
					DELY = pow((matmca_yc[j] - matmca_yc[k]),2);
					DELZ = pow((matmca_zc[j] - matmca_zc[k]),2);

					fswap2=DELX+DELY+DELZ;
					fswap2=pow(fswap2,0.5);
					seed_temp_Ca_Ca_distance_map[j][k]=fswap2;
					//printf("\ti:%3d,fswap2:%4.4f",i,seed_temp_Ca_Ca_distance_map[j][k]);
		
					if(seed_temp_Ca_Ca_distance_map[j][k]<4)	
					{
						fswap3 = fswap3 + seed_temp_Ca_Ca_distance_map[j][k];
						count++;
					}				
				}
				if(j==k)
				{
					seed_temp_Ca_Ca_distance_map[j][k]=0;
				}		
			}		
			seed_temp_ave_dist_lt_threshold_count[j]=count;
			if(count==0)
			count=count+1;
			seed_temp_ave_dist_lt_threshold[j] = fswap3/count;	
			//printf("\n Average Distance Map lt threshold for Seed_temp_Calpha %3d => %4.4f :: Count: %3d",j,
			//seed_temp_ave_dist_lt_threshold[j],seed_temp_ave_dist_lt_threshold_count[j]);
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",matmca_xc[j],matmca_yc[j],matmca_zc[j]);
			fswap2=0;fswap3=0;count=0;
		}


		//for(j=0;j<smaller_cacount;j++)
		//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
		//_____________________________________________________________________________________________

		//Distance Map for Hit template (Considered as Template PDB)
		printf("\n\n");
		j=0;DELX=0;DELY=0;DELZ=0;
		fswap2=0;fswap3=0;count=0;
		
		float temp_hit_Ca_Ca_distance_map[smaller_cacount][smaller_cacount];
		int temp_hit_ave_dist_lt_threshold_count[smaller_cacount];
		float temp_hit_ave_dist_lt_threshold[smaller_cacount];  //ave_Ca-Ca distance of Model < 5A' for each res
		j=0;k=0;

		for (j=0;j<smaller_cacount;j++)
		{	
			fswap2=0;fswap3=0;count=0;
			for (k=0;k<smaller_cacount;k++)	
			{
				if(j!=k)
				{
					DELX = pow((tatmca_xc[j] - tatmca_xc[k]),2);
					DELY = pow((tatmca_yc[j] - tatmca_yc[k]),2);
					DELZ = pow((tatmca_zc[j] - tatmca_zc[k]),2);
		
					fswap2=DELX+DELY+DELZ;
					fswap2=pow(fswap2,0.5);
					temp_hit_Ca_Ca_distance_map[j][k]=fswap2;		
					//printf("\tj:%3d,fswap2:%4.4f",j,temp_hit_Ca_Ca_distance_map[j][k]);
		
					if(temp_hit_Ca_Ca_distance_map[j][k]<4)		
					{
						fswap3 = fswap3 + temp_hit_Ca_Ca_distance_map[j][k];
						count++;
						//printf("\nCount:%3d",count);
					}						
				}		
		
				if(j==k)
				{
					temp_hit_Ca_Ca_distance_map[j][k]=0;		
				}
			}
			temp_hit_ave_dist_lt_threshold_count[j]=count;
			if(count==0)
			count=count+1;
			temp_hit_ave_dist_lt_threshold[j] = fswap3/count;	
			//printf("\n Average Distance Map lt threshold for Temp_Hit_Calpha %3d => %4.4f :: Count: %3d",j,
			//temp_hit_ave_dist_lt_threshold[j],temp_hit_ave_dist_lt_threshold_count[j]);
			//printf("\nx:%4.4f,y:%4.4f,z:%4.4f",tatmca_xc[j],tatmca_yc[j],tatmca_zc[j]);
			fswap2=0;fswap3=0;count=0;
		}

		//printf("\n\nAverage Distance Map lt threshold:");
		//for (j=0;j<smaller_cacount;j++)
		//printf("\n Residue Count; %3d ;=>\tSEED_TEMPLATE: ;%4.4f :: ;Count: ;%3d\t;TEMPLATE_HIT: ;%4.4f; :: Count;: %3d;",j,seed_temp_ave_dist_lt_threshold[j],seed_temp_ave_dist_lt_threshold_count[j], 
		//temp_hit_ave_dist_lt_threshold[j], temp_hit_ave_dist_lt_threshold_count[j]);
		


		float seed_temp_temp_hit_ave_dist_lt_threshold_analysis[smaller_cacount];

		fswap5=0;count=0;
		for (j=0;j<smaller_cacount;j++)
		{
			if(seed_temp_ave_dist_lt_threshold_count[j]==temp_hit_ave_dist_lt_threshold_count[j])
			{
			   //printf("\nTemp:%s\tseed_temp_ave_dist_lt_threshold[j]:%8.3f\ttemp_hit_ave_dist_lt_threshold[j]:%8.3f",MSA_pdbfiles[i], temp_hit_ave_dist_lt_threshold[j], temp_hit_ave_dist_lt_threshold[j]);
			   count++;		
			   seed_temp_temp_hit_ave_dist_lt_threshold_analysis[j]= fabs(seed_temp_ave_dist_lt_threshold[j] - 											 temp_hit_ave_dist_lt_threshold[j]);
				fswap5 = fswap5 + seed_temp_temp_hit_ave_dist_lt_threshold_analysis[j];
			}
		}
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_count[i]=count;
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[i]=fswap5;	//Check to divide by count
		if( seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[i] < 0)
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[i] *= (-1);
	

		//printf("\nseed_temp_temp_hit_ave_dist_lt_threshold_analysis_count:%d\n		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average:%f, ",
		//seed_temp_temp_hit_ave_dist_lt_threshold_analysis_count[i], 
		//seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[i]);

		//for(j=0;j<MSA_tempcount;j++)
		//printf("\nTemp:%shas seed_temp_temp_hit_ave_dist_lt_threshold_analysis_count:%d,              seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average:%f, ",MSA_tempnames[j],
		//seed_temp_temp_hit_ave_dist_lt_threshold_analysis_count[j],
		//seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j]);







	}








	//Automated selection of good redundant hit.
	//Check redundant identity percentage of each hit against the other ones.
	int redundant_hits[MSA_tempcount][MSA_tempcount];int redundant_hits_count[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		redundant_hits[i][j]=-1;
	}
	float redundant_hits_identity_percent[MSA_tempcount][MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;count1=0;
		for(j=0;j<MSA_tempcount;j++)
		{
			for(k=0;k<MSA_templatelen[i];k++)
			{
			    if( (i!=j) && (MSA_templatearray[i][k]==MSA_templatearray[j][k]) 
				       && (MSA_templatearray[j][k]!='-') && (MSA_templatearray[i][k]!='-'))
			    count++;
			}
			if(count>0)
			{
				a1=2*count;
				b1=MSA_actual_templatelen[i] + MSA_actual_templatelen[j];
				redundant_hits_identity_percent[i][j]=(a1/b1)*100;
				if(redundant_hits_identity_percent[i][j] >= 70)	//As used in HHPred PDB70  Culling
				{
					redundant_hits[i][j]=j;
					count1++;
					printf("\nTemp_i:%s and _j:%s has identity:%f\trh:%d",MSA_tempnames[i],
					MSA_tempnames[j],redundant_hits_identity_percent[i][j],redundant_hits[i][j]);
				}
			}
			count=0;
		}
		redundant_hits_count[i]=count1;
		//printf("\n----------Temp:%s has %d redundant hits", MSA_tempnames[i],redundant_hits_count[i]);
	}






	//Calculation of Aligned Hydrophobic and aligned Hydrophilic amino acids in seed template, hit and target.
	float aligned_MSA_hydrophobic_charges_percentage[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	aligned_MSA_hydrophobic_charges_percentage[i]=0;
	
	float a111=0;float b111=0;float c111=0;
	count=0;i=0;
	for(i=0;i<MSA_tempcount;i++)
	{
	    //printf("\nTemp:%s",MSA_tempnames[i]);
	    count=0;a111=0;b111=0;
	    for(j=0;j<MSA_targetlen;j++)
	    {
		  if( (((MSA_templatearray[i][j]=='F')||(MSA_templatearray[i][j]=='A')||(MSA_templatearray[i][j]=='G') || 			        (MSA_templatearray[i][j]=='L')||(MSA_templatearray[i][j]=='I')||(MSA_templatearray[i][j]=='M') ||   	  	                (MSA_templatearray[i][j]=='V') )) && 
		      (((MSA_templatearray[0][j]=='F')||(MSA_templatearray[0][j]=='A')||(MSA_templatearray[0][j]=='G') || 			        (MSA_templatearray[0][j]=='L')||(MSA_templatearray[0][j]=='I')||(MSA_templatearray[0][j]=='M') ||  	  	                (MSA_templatearray[0][j]=='V') ))   )
		  {
		     count++;
		     //printf("count:%d,",count);
	          }
	     }
	     a111=2*count;
	     b111=MSA_actual_templatelen[0] + MSA_actual_templatelen[i];
	     c111=a111/b111;
	     aligned_MSA_hydrophobic_charges_percentage[i]=c111*100;
	     printf("\nTemplate %s has aligned_MSA_hydrophobic_charges_percentage:%f",MSA_tempnames[i], 
	     aligned_MSA_hydrophobic_charges_percentage[i]);
	}
			
	
	float aligned_MSA_hydrophilic_charges_percentage[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	aligned_MSA_hydrophilic_charges_percentage[i]=0;
	
	a111=0;b111=0;c111=0;count=0;i=0;
	for(i=0;i<MSA_tempcount;i++)
	{
	    //printf("\nTemp:%s",MSA_tempnames[i]);
	    count=0;a111=0;b111=0;
	    for(j=0;j<MSA_targetlen;j++)
	    {
		  if( (((MSA_templatearray[i][j]=='S')||(MSA_templatearray[i][j]=='T')||(MSA_templatearray[i][j]=='Q')|| 			        (MSA_templatearray[i][j]=='N')||(MSA_templatearray[i][j]=='D')||(MSA_templatearray[i][j]=='E')||    
                        (MSA_templatearray[i][j]=='R') )) && 
		      (((MSA_templatearray[0][j]=='S')||(MSA_templatearray[0][j]=='T')||(MSA_templatearray[0][j]=='Q')|| 	 	        (MSA_templatearray[0][j]=='N')||(MSA_templatearray[0][j]=='D')||(MSA_templatearray[0][j]=='E')||   	  	                (MSA_templatearray[0][j]=='R') ))   )
		  {
		     count++;
		     //printf("count:%d,",count);
	          }
	     }
	     a111=2*count;
	     b111=MSA_actual_templatelen[0] + MSA_actual_templatelen[i];
	     c111=a111/b111;
	     aligned_MSA_hydrophilic_charges_percentage[i]=c111*100;
	     printf("\nTemplate %s has aligned_MSA_hydrophobic: %8.4f\thydrophilic:%8.4f",MSA_tempnames[i],          
	     aligned_MSA_hydrophobic_charges_percentage[i],aligned_MSA_hydrophilic_charges_percentage[i]);
	}
	
	




	//CALCULATION OF COMBINED SEED_TEMPLATE AND TEMPLATE HIT COVERAGE SPAN
	count=0;a1=0;b1=0;count1=0;
	float combined_seed_hit_coverage_span_atleast_one_being_residue[MSA_tempcount];
	float combined_seed_hit_coverage_span_both_being_residue[MSA_tempcount];
	float combined_seed_hit_gap_span[MSA_tempcount];
	
	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;count1=0;count2=0;
		for(j=0;j<MSA_targetlen;j++)
		{
			if((MSA_templatearray[0][j]!='-') || (MSA_templatearray[i][j]!='-'))
			count++;
	
			if((MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][j]!='-'))
			count1++;
			
			if((MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][j]!='-') && (MSA_targetarray[j]=='-'))
			count2++;
		}
		a1=count;
		b1=MSA_templatelen[i];
		combined_seed_hit_coverage_span_atleast_one_being_residue[i]=(a1/b1)*100;
	
		a1=count1;
		b1=MSA_templatelen[i];
		combined_seed_hit_coverage_span_both_being_residue[i]=(a1/b1)*100;
		
		a1=count2;
		b1=MSA_templatelen[i];
		combined_seed_hit_gap_span[i]=(a1/b1)*100;
	
		printf("\nTemp:%s has combined_seed_hit_cover_span_atleast_1_res.:%5.3f,both residue:%5.3f,gap:%5.3f",
		MSA_tempnames[i],combined_seed_hit_coverage_span_atleast_one_being_residue[i],
		combined_seed_hit_coverage_span_both_being_residue[i],combined_seed_hit_gap_span[i]);
	}


	



	//Structural Comparison score of hits against the seed template
	float ave_per_aligned_residue_CA_GDT_score[MSA_tempcount];
	float ave_per_aligned_residue_CA_RMSD[MSA_tempcount];
	for(j=0;j<MSA_tempcount;j++)
	{
		ave_per_aligned_residue_CA_GDT_score[j]=temphit_ca_GDT_TS[j]/temphit_ca_GDT_residues[j];
		ave_per_aligned_residue_CA_RMSD[j]=best_temp_CA_RMS[j]/temphit_ca_GDT_residues[j];
	}


	float seed_temphit_structure_comparison_score[MSA_tempcount];
	a1=0;b1=0;
	for(j=0;j<MSA_tempcount;j++)
	{
		a1=0;b1=0;
	
		a1=INI_temphit_ca_GDT_residues[j]/100;
		a1=a1 + INI_temphit_ca_GDT_TS[j];
		a1=a1 + INI_ca_noa1percent[j] + INI_ca_noa2percent[j] + INI_ca_noa4percent[j] + INI_ca_noa8percent[j];
		a1=a1 + seed_hit_opti_TM_Score[j];
	
	//	b1=best_temp_CA_RMS[j];
		b1=INI_CA_RMS[j];
		b1=b1 + seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j] + tt_length_difference[j];

		seed_temphit_structure_comparison_score[j]=a1/b1; //Equation for Structural Score. Recheck again.
	}





/*
	//----------------------------------- RANK SCORE, DECREMENT ORDER OF THE STRUCTURAL SCORE STARTS----------
	int distant_redundant_hits[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	distant_redundant_hits[i]=(-1);
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		{
			if(redundant_hits[i][j]>0)
			{
				printf("\nThe templates %s and %s are redundant in MSA. Keep one with Higher TM-Score",MSA_tempnames[i],MSA_tempnames[j]);			
				if(seed_hit_opti_TM_Score[i] < seed_hit_opti_TM_Score[j])
				{
					printf("\nKeep template %s", MSA_tempnames[j]);
					distant_redundant_hits[i]=i;
					printf("\nTemp:%s",MSA_tempnames[i]);
				}
				else if (seed_hit_opti_TM_Score[j] < seed_hit_opti_TM_Score[i])
				{
					printf("\nKeep template %s", MSA_tempnames[i]);
					distant_redundant_hits[i]=j;
					printf("\nTemp:%s",MSA_tempnames[j]);
				}
			}
		}
	}
	printf("\n");

	for(j=0;j<MSA_tempcount;j++)
	printf("\nTemp:%6s: GDT_Res:%4d   TM_Score:%6.3f   GDT:%6.3f RMSD:%6.3f, DISTANCE:%6.3f",MSA_tempnames[j],
	seed_hit_mean_model_ca_GDT_residues[j],seed_hit_mean_model_TM_Score[j],seed_hit_mean_model_ca_GDT_TS[j], 		seed_hit_mean_model_INI_CA_RMS[j],seed_hit_mean_model_ca_avg_distance[j]);
*/






	//DNC for finding distant hits
	int distant_templates_count;int distant_templates[MSA_tempcount];count=0; 
	for(i=0;i<MSA_tempcount;i++)
	distant_templates[i]=0;

	a1=0;
	for(i=1;i<MSA_tempcount;i++)
	{
		if( 
	   (seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[i]>=10) 			      
	|| (INI_CA_RMS[i]>=10)     
	|| (seed_hit_opti_TM_Score[i]<0.5) 
	|| ((seed_hit_opti_TM_Score[i]>=0.975) && (additional_span[i]<4))
	|| (INI_temphit_ca_GDT_residues[i]==0) 
	|| (additional_span[i]<4)  
	//|| (MSA_ttidentpercent[i]<=5) //
	//   (abs(seed_template_hit_span[0] - seed_template_hit_span[i])>=30 )   			      
	//|| (ca_noa1percent[i]<=2)         	|| (ca_noa2percent[i]<=15)   
	//|| (ca_noa4percent[i]<=25)        	|| (ca_noa8percent[i]<=50)   
	//|| ( (abs(tt_length_difference[i]-tt_length_difference[0]))>=(0.25*MSA_actual_templatelen[0]))        
	//|| (  (fabs(MSA_ttidentpercent[0]-MSA_ttidentpercent[i])>20) && (MSA_ttidentpercent[0]>50)  )       
	//|| (distant_redundant_hits[i]>0)  
	//|| (seed_template_hit_span[i]<75)  
	//   ( fabs(average_fold_length[i]-average_fold_length[0]) < (0.3*average_fold_length[0]) ) 
		    )
		{
			distant_templates[i]=i;
			count++;
			continue;  //Check this out again for good MSA Filtering Result
		}
		
		else		
		{
			a1 = a1 + seed_temphit_structure_comparison_score[i];
			distant_templates[i]=0;
			//printf("\nTemp:%s,distant:%d",MSA_tempnames[i],distant_templates[i]);
		}
	}
	distant_templates_count=count;


	float avg_struc_similarity_score=a1/(MSA_tempcount - distant_templates_count + 1);
	//printf("\n\nAvg. similarity_score:%9.3f",avg_struc_similarity_score);




	int fcount21=0;
	for(i=0;i<MSA_tempcount;i++)
	{
	       if(MSA_tempcount==distant_templates_count)
	       {
	      		fcount21=fcount21 + 
			((seed_temphit_structure_comparison_score[i]- avg_struc_similarity_score)*
			 (seed_temphit_structure_comparison_score[i]- avg_struc_similarity_score))/
			 (MSA_tempcount - distant_templates_count + 1);  
			//printf("\nScore:%f,fcount21:%f",seed_temphit_structure_comparison_score[i],fcount21);
		}
		else
		{
			fcount21=fcount21+((seed_temphit_structure_comparison_score[i] - avg_struc_similarity_score) * 
					 (seed_temphit_structure_comparison_score[i] - avg_struc_similarity_score))/
					 (MSA_tempcount - distant_templates_count);  
			//printf("\nScore:%f,fcount21:%f",seed_temphit_structure_comparison_score[i],fcount2);
		}	
	}
	float struc_std_deviation=pow(fcount21,0.5);
	//printf("\n\nStd deviation:%f,avg_similarity_score:%f\n",struc_std_deviation,avg_struc_similarity_score);



	float rank_struc_similarity_score[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		rank_struc_similarity_score[i]=(seed_temphit_structure_comparison_score[i] - avg_struc_similarity_score)/
						struc_std_deviation;
		//printf("\nTemplate %s has MSA_Score:%9.3f, rank_similarity_score:%9.3f",MSA_tempnames[i],
		//	seed_temphit_structure_comparison_score[i], rank_struc_similarity_score[i]);
	}


	
	//Calculating overlap of seed template with different hits.
	count=0;float a2=0;float b2=0;
	float MSA_seed_temp_overlap_score_percentage[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{    
		count=0;a2=0;b2=0;
	     	for(j=0;j<MSA_templatelen[i];j++)
		{
			if( (MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][j]!='-')) 			
			count++;
		}
		a2=count;
		b2=MSA_templatelen[i];
		MSA_seed_temp_overlap_score_percentage[i]=(a2/b2)*100;
		printf("\nTemp:%s has overlap:%f",MSA_tempnames[i],MSA_seed_temp_overlap_score_percentage[i]);
	}
		
		     	














	//Calculating TM_Score for each hit against the other hit
	int MSA_hit_hit1_aligned_residue_positions[MSA_targetlen]; //B4 MSA_seed_residue_aligned_positions
	int MSA_hit_hit2_aligned_residue_positions[MSA_targetlen]; //B4 MSA_temphit_residue_aligned_positions
	int MSA_hit1_hit2_aligned_residues[MSA_tempcount][MSA_tempcount];         //B4 MSA_seed_aligned_residues


	for(j=0;j<MSA_targetlen;j++)
	{
		MSA_hit_hit1_aligned_residue_positions[j]=-1;
		MSA_hit_hit2_aligned_residue_positions[j]=-1;
	}
	for(j=0;j<MSA_tempcount;j++)
	{
		for(k=0;k<MSA_tempcount;k++)
		MSA_hit1_hit2_aligned_residues[j][k]=-1;
	}
	//_____________________________________________________________________________________________________________
	
	count=0;

	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		{
			count=0;
	 	   	for(k=0;k<MSA_templatelen[j];k++)
		        {
				if(  (MSA_templatearray[i][k]!='-') && (MSA_templatearray[j][k]!='-')  )
				{
					MSA_hit_hit1_aligned_residue_positions[k]=k;
					MSA_hit_hit2_aligned_residue_positions[k]=k;
					//printf("\t\tSeed:%s has %3d,Hit: %s has %3d, Seed:%c,Hit:%c\t",MSA_tempnames[i],
					//MSA_hit_hit1_aligned_residue_positions[k],MSA_tempnames[j],
					//MSA_hit_hit2_aligned_residue_positions[k],MSA_templatearray[i][k],
					//MSA_templatearray[j][k]);
					count++;
				}
			}
			//printf("\n========>At %3d,Seed:%c,Hit:%c\t",MSA_hit_hit1_aligned_residue_positions[k],
			//MSA_templatearray[i][k],MSA_templatearray[j][k]);
			MSA_hit1_hit2_aligned_residues[i][j]=count;
			//printf("\n\tTemplate %s with Template %s has %d aligned residues",MSA_tempnames[i],
			//MSA_tempnames[j],MSA_hit1_hit2_aligned_residues[i][j]);
			//_____________________________________________________________________________
		}
	}














	//HIT_HIT_SEQUENCE_IDENTITY_SCORE CALCULATION STARTS HERE
	float MSA_hit_hit_sequence_identity_percentage[MSA_tempcount][MSA_tempcount];
	int MSA_highly_seq_identical_hits[MSA_tempcount][MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		MSA_highly_seq_identical_hits[i][j]=(-1);
	}

	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		{	
			printf("\nIdentity of HIT1:%s",MSA_tempnames[i]);
			printf("with %s is:",MSA_tempnames[j]);
			count=0;
			for(k=0;k<MSA_templatelen[i];k++)
			{
				if(MSA_templatearray[i][k]==MSA_templatearray[j][k])
				count++;
			}
		a1=count;
		b1=MSA_templatelen[i];
		MSA_hit_hit_sequence_identity_percentage[i][j]=(a1/b1)*100;
		printf("%10.6f",MSA_hit_hit_sequence_identity_percentage[i][j]);
		if(MSA_hit_hit_sequence_identity_percentage[i][j]>70)
		MSA_highly_seq_identical_hits[i][j]=2;
		}
		printf("\n___________________________________________________________");
	}
	printf("\n");
	//HIT_HIT_SEQUENCE_IDENTITY_SCORE CALCULATION ENDS HERE

	int numswap1=0;
	printf("\n<==============================================================================================>");
	for(i=0;i<MSA_tempcount;i++)
	{
		for(k=0;k<MSA_tempcount;k++)
		{
			if( (MSA_highly_seq_identical_hits[i][k]==2) && (i!=k) )
			numswap1++;
			else
			continue;
		}
			
		if(numswap1>0)			
		printf("\nTemplate %s is ",MSA_tempnames[i]);
		for(j=0;j<MSA_tempcount;j++)
		{
			if( (MSA_highly_seq_identical_hits[i][j]==2) && (i!=j)  )
			{
				printf("\n\t\t\t%6.2f ident. to %s",
				MSA_hit_hit_sequence_identity_percentage[i][j],MSA_tempnames[j]);
			}
		}
		numswap1=0;
	}

	k1=0;
	printf("\nSTRUCTURALLY SIMILAR TEMPLATE CLUSTERS:");
	for(i=0;i<MSA_tempcount;i++)
	{
		for(k=0;k<MSA_tempcount;k++)
		{
			if( (MSA_highly_seq_identical_hits[i][k]==2) && (i!=k) )
			numswap1++;
		}
		if(numswap1>0)			
		{
			printf("\nCLUSTER %3d: %6s SIMILAR HITS:",k1+1,MSA_tempnames[i]);
			k1++;
		}
		
		
		for(j=0;j<MSA_tempcount;j++)
		{
			if( (MSA_highly_seq_identical_hits[i][j]==2) && (i!=j)  )
			{
				printf("%6s",MSA_tempnames[j]);
			}
		}
		numswap1=0;
	}

	printf("\n");






//MSA_template_Offset (Lesser is Better) and Seed_hit_combined_coverage_span of the templates Starts
	//Calculation of Seed_Hit_Combined_Coverage_Span over the target sequence
	k=0;
	int MSA_seqstartpos[MSA_tempcount];int MSA_seqendpos[MSA_tempcount];
	count=0;j=0;
	//MSA_igstart_template[i],MSA_egstart_template[i],MSA_igstart_target,MSA_egstart_target

	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;j=0;
	        while ( ((MSA_templatearray[i][j]=='-') && (MSA_templatearray[0][j]=='-')) && (MSA_targetarray[j]=='-')  )
	        {
			count++;
			j++;
		}
		MSA_seqstartpos[i]=count;
		//printf("\nTemp %s Start is found at %d position out of %d",MSA_tempnames[i],MSA_seqstartpos[i], 			MSA_templatelen[i]);
	}

	count=0;k=0;i=0;j=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		j=MSA_templatelen[i]-1;
	        while ( ((MSA_templatearray[i][j]=='-') && (MSA_templatearray[0][j]=='-')) && (MSA_targetarray[j]=='-')  )
	        {
			count++;
			j--;
		}
		MSA_seqendpos[i]=count;
		//printf("\nTemp %s has Ending Residue is found at %d position out of %d",MSA_tempnames[i], 			MSA_seqendpos[i],MSA_templatelen[i]);
		count=0;j=0;
	}


float seed_hit_combined_target_cover_span[MSA_tempcount];
	a1=0;b1=0;int MSA_hit_offset[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	MSA_hit_offset[i] = MSA_seqstartpos[i] + MSA_seqendpos[i] + 1;
	float fa11=0;float fa12=0;float fa13=0;
	float fb11=0;float fb12=0;float fb13=0;

	for(i=0;i<MSA_tempcount;i++)
	{
		fa11=(MSA_templatelen[i] - MSA_seqendpos[i]) - MSA_seqstartpos[i] + 1;
		fa12=MSA_templatelen[i];
		fa13=(fa11/fa12)*100;

		fb11=(MSA_templatelen[0] - MSA_seqendpos[0]) - MSA_seqstartpos[0] + 1;
		fb12=MSA_templatelen[0];
		fb13=(fb11/fb12)*100;
		
		if(fa13<fb13)
		seed_hit_combined_target_cover_span[i]=fb13;
		else 
		seed_hit_combined_target_cover_span[i]=fa13;
		a1=0;b1=0;	
		printf("\nTemp %s has seed_hit_combined_target_cover_span:%10.4f, Offset:%4d",MSA_tempnames[i], 
  	        seed_hit_combined_target_cover_span[i],MSA_hit_offset[i]); 
	}
//MSA_template_Offset (Lesser is Better) and Seed_hit_combined_coverage_span of the templates Ends




	



//for(i=0;i<MSA_tempcount;i++)
//printf("\nTemp:%s sh_mean_model_ca_avg_distance:%6.3f,RMS:%6.3f,TM_Score:%6.3f,GDT_TS:%6.3f,score:%6.5f",MSA_tempnames[i],seed_hit_mean_model_ca_avg_distance[i],seed_hit_mean_model_INI_CA_RMS[i], seed_hit_mean_model_TM_Score[i],seed_hit_mean_model_ca_GDT_TS[i],seed_temphit_structure_comparison_score[i]);









//MSA_Score Function..............CALCULATION OF MSA SEQUENCE SCORE NOW STARTS HERE.............
	
	for(i=1;i<MSA_tempcount;i++)
	{    
	     a1=0;b1=0;
	     //Check this equation again
	     // MSA_ttidentpercent[i]   temphit_ca_GDT_residues[j]  	temphit_ca_GDT_TS[j]
             // seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j], 
	     //ca_noa1percent[j]	ca_noa2percent[j]		ca_noa4percent[j]	 ca_noa8percent[j]
// 	     a1=fabs(MSA_tt_blosum62score[i])*50 + MSA_st_blosum62score[i]*50;		// Used Earlier
	     //  Add this to the equation now in numerator
	     // Add this also in the equation  corresponding_cover_span_difference_of_hit_against_seed_template[i], 			 			       corresponding_cover_span_of_hit_against_target[i]

//Deleted tt_length_difference[i],MSA_reschunk_count[i],MSA_st_blosum62score[i],MSA_st_ttidentpercent[i],
//MSA_actual_templatelen[i],temphit_smaller_cacount[i],INI_SC_RMS[i],INI_temphit_sc_GDT_residues[i],INI_temphit_sc_GDT_TS[i], INI_ca_noa1percent[i],INI_ca_noa2percent[i],INI_ca_noa4percent[i],seed_temphit_structure_comparison_score[i] from the final MSA_Score score printing table


	     //a1= MSA_st_blosum62score[i];
   	     a1= a1  + additional_span[i]/2 + unique_residues[i];
	     a1= a1 + (MSA_ttidentpercent[i]*2 + MSA_st_ttidentpercent[i]/2 + MSA_profile_ttidentpercent[i]/2)/3;
	     a1= a1 + aligned_MSA_hydrophobic_charges_percentage[i]/2 + aligned_MSA_hydrophilic_charges_percentage[i];
	     a1= a1 + combined_seed_hit_coverage_span_atleast_one_being_residue[i]*2;
	     a1= a1 + combined_seed_hit_coverage_span_both_being_residue[i]/2;
	     a1= a1 + seed_hit_mean_model_ca_GDT_residues[i];   	//Added1
	     a1= a1 + seed_hit_mean_model_ca_GDT_TS[i];         	//Added2
	     a1= a1 + seed_hit_mean_model_TM_Score[i];        	  	//Added3
	    // a1= a1 + seed_hit_combined_target_cover_span[i];		//Removed after checking its wrong effect and will 										be later used in template combination module later.
	     a1= a1 + seed_temphit_structure_comparison_score[i];	//Added6
	
    	     b1=fabs(MSA_unspanned_residues[i] - MSA_unspanned_residues[0])*100;
	     b1= b1+ (tt_length_difference[i]/2 + seed_hit_length_difference[i])/2; 
	     //b1= b1+ ave_MSA_chunklength_based_distance[i]; 
	     b1= b1+ MSA_reschunk_count_difference[i];
	     //b1= b1+ (fabs(average_fold_length[i]-average_fold_length[0]))*50;
	     b1= b1+ combined_seed_hit_gap_span[i];
	     b1= b1 + MSA_seed_temp_overlap_score_percentage[i];
	     b1= b1 + RDWV_seed_hit_change[i];
	     b1= b1 + seed_hit_mean_model_INI_CA_RMS[i];		//Added4
  	     b1= b1 + seed_hit_mean_model_ca_avg_distance[i];   	//Added5
	     //b1= b1 + abs(MSA_hit_offset[i] - MSA_hit_offset[0]); 	//Removed after checking its wrong effect and will 										be later used in template combination module later.

	     if(b1==0)          
	     b1=b1+1;           
 	     returnscore=(a1/b1);
	

	     //MSA_actual_templatelen[j],tt_length_difference[i], MSA_aligned_commonsites[j],ave_MSA_temp_chunklengths[j], 
	     //	ave_MSA_chunklength_based_distance[j], MSA_ttidentpercent[j],MSA_st_ttidentpercent[j], 			    
	     //	MSA_profile_ttidentpercent[j], MSA_reschunk_count[j], 
	     //	MSA_unspanned_residues[j],MSA_Score1[j],rank_similarity_score[j], i);
		printf("\nUR:%f   CBD:%f  \tTemp:%s. numr=%f, dinr=%f",MSA_unspanned_residues[i], 
		ave_MSA_chunklength_based_distance[i], MSA_tempnames[i],a1,b1);

	     if(returnscore<0)
	     returnscore=returnscore*(-1);
	     //printf("\ntemplate %s returnscore is: %5.4f, unspannd_residues[i]:%f,ave_MSA_chunklen_based_distance:%f"
	     //,MSA_tempnames[i],returnscore,MSA_unspanned_residues[i], ave_MSA_chunklength_based_distance[i]);
	     MSA_Score1[i]=returnscore;
	}





	//DNC for score calculation
	a1=0;
	for(i=1;i<MSA_tempcount;i++)
	{
		if( 
	   (seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[i]>=10) 			      
	|| (INI_CA_RMS[i]>=10)     
	|| (seed_hit_opti_TM_Score[i]<0.5) 
	|| ( (seed_hit_opti_TM_Score[i]>=0.975) && (additional_span[i]<4) )
	|| (INI_temphit_ca_GDT_residues[i]==0) 
	|| (additional_span[i]<4)  
	//(MSA_ttidentpercent[i]<=5) //
	//        (abs(seed_template_hit_span[0] - seed_template_hit_span[i])>=30 )   			      
	//||	   (ca_noa1percent[i]<=2)         	|| (ca_noa2percent[i]<=15)   
	//||	   (ca_noa4percent[i]<=25)        	|| (ca_noa8percent[i]<=50)   
	//||	   ( (abs(tt_length_difference[i]-tt_length_difference[0]))>=(0.25*MSA_actual_templatelen[0]))        
	//||	   (  (fabs(MSA_ttidentpercent[0]-MSA_ttidentpercent[i])>20) && (MSA_ttidentpercent[0]>50)  )       
	//|| 	   (distant_redundant_hits[i]>0)  
	//||	   (seed_template_hit_span[i]<75)  
	// 	   ( fabs(average_fold_length[i]-average_fold_length[0]) < (0.3*average_fold_length[0]) ) 
		    )
		{
			printf("\nTemp:%s is useless",MSA_tempnames[i]);
			continue;  
		}
		else	
		a1=a1+MSA_Score1[i];
	}
	float avg_similarity_score=a1/(MSA_tempcount - distant_templates_count + 1);
	//printf("\n\nAvg. similarity_score:%9.3f",avg_similarity_score);




	float fcount2=0;
	for(i=1;i<MSA_tempcount;i++)
	{
		if(MSA_tempcount==distant_templates_count)
		{	fcount2=fcount2+( (MSA_Score1[i] - avg_similarity_score) * (MSA_Score1[i] - avg_similarity_score) )/
				  (MSA_tempcount - distant_templates_count + 1);  
			//printf("\nScore:%f,fcount2:%f",MSA_Score1[i],fcount2);
		}
		else
		{
			fcount2=fcount2+( (MSA_Score1[i] - avg_similarity_score) * (MSA_Score1[i] - avg_similarity_score) )/
				  (MSA_tempcount - distant_templates_count);  
			//printf("\nScore:%f,fcount2:%f",MSA_Score1[i],fcount2);
		}	
	}
	float std_deviation=pow(fcount2,0.5);
	//printf("\n\nStd deviation:%f,avg_similarity_score:%f\n",std_deviation,avg_similarity_score);



	float rank_similarity_score[MSA_tempcount];
	for(i=1;i<MSA_tempcount;i++)
	{
		rank_similarity_score[i]=(MSA_Score1[i] - avg_similarity_score)/std_deviation;
		//printf("\nTemplate %s has MSA_Score:%9.3f, rank_similarity_score:%9.3f",MSA_tempnames[i],MSA_Score1[i], 			rank_similarity_score[i]);
	}

	printf(" ");
	if (system( "clear" )) system( "cls" );

	float MSA_Score1dup[MSA_tempcount];
	for (i=1;i<MSA_tempcount;i++)
	MSA_Score1dup[i]=rank_similarity_score[i];

	int orderedtemplates=MSA_tempcount;
	int MSA_tempdecre_order[orderedtemplates];
	for(i=0;i<(orderedtemplates);i++)
	MSA_tempdecre_order[i]=i;
	float swap1f=0;
	


int count_different_span_templates;
for(i=1;i<MSA_tempcount;i++)
{
	if(additional_span[i]!=additional_span[i-1])
	count++;
}
count_different_span_templates=count;
printf("\nCount:%d",count_different_span_templates);

int count_different_span_templates_values[count_different_span_templates];count=0;
for(i=1;i<(MSA_tempcount-1);i++)
{
	if(additional_span[i+1]!=additional_span[i])
	{
		count_different_span_templates_values[count]=additional_span[i];
		count++;
		count_different_span_templates_values[count]=additional_span[i+1];
		printf("\n%dth temp added span is :%d",count,count_different_span_templates_values[count]);
	}
	else
	continue;
}

int different_temp_span_count=count_different_span_templates;
int different_temp_span[count_different_span_templates];

printf("\n");
for(i=0;i<count_different_span_templates;i++)
{
	different_temp_span[i]=count_different_span_templates_values[i];
	printf("\n%d,different span:%d",i,count_different_span_templates_values[i]);
}
printf("\n");

for(i=0;i<different_temp_span_count;i++)
printf("\n%d,different span:%d",i,different_temp_span[i]);
for (i=1;i<different_temp_span_count;i++)
{
    for(j=i+1;j<different_temp_span_count;j++)
    {
  	    if( (different_temp_span[j]>=different_temp_span[i])  )
	    {
		swap1 = different_temp_span[j];
	  	different_temp_span[j] = different_temp_span[i];
		different_temp_span[i] = swap1;
	    }
     }
 }
for(i=0;i<different_temp_span_count;i++)
printf("\n=====>%d,different span:%d",i,different_temp_span[i]);
	



for(k=0;k<different_temp_span_count;k++)
{
	for (i=1;i<orderedtemplates;i++)
	{
	    for(j=i+1;j<orderedtemplates;j++)
	    {
		if( (additional_span[i]==different_temp_span[k]) && (additional_span[j]==different_temp_span[k]) )
		{
	  	    if( (MSA_Score1dup[j]>=MSA_Score1dup[i])  )
		    {
			if((additional_span[j]>=additional_span[i]) )
			{
				swap1 = MSA_tempdecre_order[j];
			  	MSA_tempdecre_order[j] = MSA_tempdecre_order[i];
				MSA_tempdecre_order[i] = swap1;
			}
		        swap1f = MSA_Score1dup[j];
			MSA_Score1dup[j] = MSA_Score1dup[i];
			MSA_Score1dup[i] = swap1f;
		    }
		}
	     }
	 }
}






//Sorting order as per decreasing order of their rank_similarity_score or Z-Score
float MSA_Score2dup[MSA_tempcount];
for (i=1;i<MSA_tempcount;i++)
MSA_Score2dup[i]=rank_similarity_score[i];

int MSA_rank_tempdecre_order[MSA_tempcount];
for(i=0;i<(MSA_tempcount);i++)
MSA_rank_tempdecre_order[i]=i;
printf("\n");
swap1=0;swap1f=0;

for (i=1;i<MSA_tempcount;i++)
{
    for(j=i+1;j<MSA_tempcount;j++)
    {
      if((MSA_Score2dup[j]>MSA_Score2dup[i]))
      {
	  swap1 = MSA_rank_tempdecre_order[j];
	  MSA_rank_tempdecre_order[j] = MSA_rank_tempdecre_order[i];
	  MSA_rank_tempdecre_order[i] = swap1;
	  
	  swap1f = MSA_Score2dup[j];
	  MSA_Score2dup[j] = MSA_Score2dup[i];
	  MSA_Score2dup[i] = swap1f;

      }
    }
 }
//Sorting order as per decreasing order of their rank_similarity_score or Z-Score is Done here








/*
//Finding Redundant Hit Entries in MSA_tempcount
	count=0;int swap11=0;int swap12=0;
	count1=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		{
			if( (redundant_hits[i][j]>0) && (redundant_hits[i][j]!=swap11) && (redundant_hits[i][j]!=swap12) )
			{
				count++;
				if(seed_hit_opti_TM_Score[i] < seed_hit_opti_TM_Score[j])
				{
					if( (redundant_hits[i][j]!=swap11) && (distant_redundant_hits[j]!=swap12) )
					{
						printf("\n\t%d.\tThe templates %s and %s are redundant. Keep the one with Higer TM-Score, i.e ",count,MSA_tempnames[i],MSA_tempnames[j]);
						printf("Use %s", MSA_tempnames[j]);
						count1++;
						distant_redundant_hits[j]=i;
						swap11=redundant_hits[i][j];
						swap12=distant_redundant_hits[j];
					}

				}
				else if (seed_hit_opti_TM_Score[j] < seed_hit_opti_TM_Score[i])
				{
					if( (redundant_hits[i][j]!=swap11) && (distant_redundant_hits[j]!=swap12) )
					{
						printf("\n\t%d.\tThe templates %s and %s are redundant. Keep the one with Higer TM-Score, i.e. ",count,MSA_tempnames[i],MSA_tempnames[j]);
						printf("Use %s", MSA_tempnames[i]);
						count1++;
						distant_redundant_hits[j]=j;
						swap11=redundant_hits[i][j];
						swap12=distant_redundant_hits[j];
						//printf("\tswap11:%d,swap12:%d",swap11,swap12);
					}
				}
			}
		}
	}


	printf("\n");
	int MSA_redundant_hit_entries_pair_count=count1;
	int MSA_redundant_hit_entries[MSA_redundant_hit_entries_pair_count][2];
	count=0;swap11=0;swap12=0;
	count1=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0;j<MSA_tempcount;j++)
		{
			if( (redundant_hits[i][j]>0) && (redundant_hits[i][j]!=swap11) && (redundant_hits[i][j]!=swap12) )
			{
				count++;
				if(seed_hit_opti_TM_Score[i] < seed_hit_opti_TM_Score[j])
				{
					if( (redundant_hits[i][j]!=swap11) && (distant_redundant_hits[j]!=swap12) )
					{
						printf("Use %s", MSA_tempnames[j]);
						MSA_redundant_hit_entries[count1][0]=i;
						MSA_redundant_hit_entries[count1][1]=j;
						printf("\n\t%d.\tThe templates %s and %s are redundant. Keep the one with Higer TM-Score, %d, i.e. ",count,MSA_tempnames[i],MSA_tempnames[j],count1);

						count1++;
						distant_redundant_hits[j]=i;
						swap11=redundant_hits[i][j];
						swap12=distant_redundant_hits[j];
					}

				}
				else if (seed_hit_opti_TM_Score[j] < seed_hit_opti_TM_Score[i])
				{
					if( (redundant_hits[i][j]!=swap11) && (distant_redundant_hits[j]!=swap12) )
					{
						printf("Use %s", MSA_tempnames[i]);
						MSA_redundant_hit_entries[count1][0]=i;
						MSA_redundant_hit_entries[count1][1]=j;
						printf("\n\t%d.\tThe templates %s and %s are redundant. Keep the one with Higer TM-Score, %d, i.e. ",count,MSA_tempnames[i],MSA_tempnames[j],count1);

						count1++;
						distant_redundant_hits[j]=j;
						swap11=redundant_hits[i][j];
						swap12=distant_redundant_hits[j];
						//printf("\tswap11:%d,swap12:%d",swap11,swap12);
					}
				}
			}
		}
	}

//Finding Redundant Hit Entries in MSA_tempcount is Done Here
*/















for(j=0;j<MSA_tempcount;j++)
printf("\nTemp:%6s: GDT_Res:%4d   TM_Score:%6.3f   GDT:%6.3f\tRMSD:%6.3f\tDISTANCE:%6.3f",MSA_tempnames[j],
seed_hit_mean_model_ca_GDT_residues[j],seed_hit_mean_model_TM_Score[j],seed_hit_mean_model_ca_GDT_TS[j], 	seed_hit_mean_model_INI_CA_RMS[j],seed_hit_mean_model_ca_avg_distance[j]);


int good_templates[MSA_tempcount];	//Store 1 for good templates in this array else it has -1 for bad templates in 
					//the array good_templates[MSA_tempcount]
for(i=0;i<MSA_tempcount;i++)
good_templates[i]=-1;

printf("\n");
if (system( "clear" )) system( "cls" );
printf("\n\tSEQUENCE  AND STRUCTURAL TOPOLOGY ANALYSIS RESULT OF TEMPLATE HITS AGAINST THE TARGET\t   TARGET LENGTH:%4d",MSA_actual_targetlen);
printf("\n________________________________________________________________________________________________________________________     ");
printf(" RESULTS==>| \t\tSEQUENCE ANALYSIS\t           |\t    STRUCTURAL ANALYSIS\t     |\t    OVERALL SCORE      |  "); 
printf("\n___________|_______________________________________________|_________________________________|_________________________|");
printf("\n TEMP |TEMP|COMMON| AVE.| TARG | NON  |BLOSUM| SEED |UNIQUE|      |CA |CALPHA|SEED_HIT|      |  MSA  |  Z   |RANK|ADDED|");
printf("\n      |LEN | SEQ. |CHUNK| TEMP |SPAN'D|SCORE | COVER| RES. |  CA  |GDT|GDT_TS|  MAP   |      | SCORE | SCORE|    |TARG.|");
printf("\n      |    | FOLDS| LEN | IDEN | RES. |TARGET| SPAN | SPAN | RMSD |RES|SCORE |  AVE   |  TM  |       |      |    |     |");	
printf("\n______|____|______|_____|_TITY_|______|_TEMP_|______|_RES._|______|___|______|__DIFF__|SCORE_|_______|______|____|_____|");
j=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		j=MSA_rank_tempdecre_order[i];	
		//MSA_tt_blosum62score[i],MSA_st_blosum62score[i]
		if(i==0)
		{
			printf("\n%6s|%4d| %4d |%5.2f|%6.2f|%6.3f|%6.2f| SEED | SEED | %4.3f|%3d|%6.2f|%8.4f|%5.4f| SEED  | SEED |SEED| SEED", MSA_tempnames[j],MSA_actual_templatelen[j],MSA_aligned_commonsites[j],
			average_fold_length[j],	MSA_ttidentpercent[j],MSA_unspanned_residues[j],
			MSA_tt_blosum62score[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
			seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j]);
			good_templates[i]=1;
		}

		else if((i>0) && (distant_templates[j]==0))
		{
			printf("\n%6s|%4d| %4d |%5.2f|%6.2f|%6.3f|%6.3f|%6.2f|%4d  |%6.3f|%3d|%6.3f|%8.4f|%5.4f|%7.3f|%6.3f|%3d |%3d  |",MSA_tempnames[j],MSA_actual_templatelen[j], MSA_aligned_commonsites[j],average_fold_length[j],
			MSA_ttidentpercent[j],MSA_unspanned_residues[j],MSA_tt_blosum62score[j],seed_template_hit_span[j],
			unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
			seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j], 				rank_similarity_score[j], i,additional_span[j]);
			good_templates[j]=1;
		}

		else if((i>0) && (distant_templates[j]>0) )
		{
		printf("\n%6s|%4d| %4d |%5.2f|%6.2f|%6.3f|%6.3f|%6.2f|%4d  |%6.3f|%3d|%6.3f|%8.4f|%5.4f|%7.3f|%6.3f|%3d |%3d  =>DNC",MSA_tempnames[j],MSA_actual_templatelen[j], MSA_aligned_commonsites[j],
			average_fold_length[j], MSA_ttidentpercent[j],
			MSA_unspanned_residues[j],MSA_tt_blosum62score[j],seed_template_hit_span[j],
			unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
			seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j],
			rank_similarity_score[j], i, additional_span[j]);
			good_templates[j]=-1;
		}

/*		else if((i>0) && (distant_redundant_hits[j]>0))
		{
			//MSA_redundant_hit_entries[MSA_redundant_hit_entries_pair_count][2]
			for(k=0;k<MSA_redundant_hit_entries_pair_count;k++)
			{
				if(  (j==MSA_redundant_hit_entries[k][0]) || (j==MSA_redundant_hit_entries[k][1])  )
				{
					printf("\n%6s|%4d| %4d |%5.2f|%6.2f|%6.3f|%6.3f|%6.2f|%4d  |%6.3f|%3d|%6.3f|%8.4f|%5.4f|%7.3f|%6.3f|%3d |%3d =>RH_%d",
					MSA_tempnames[j],MSA_actual_templatelen[j],MSA_aligned_commonsites[j],
					average_fold_length[j], MSA_ttidentpercent[j],
					MSA_unspanned_residues[j],MSA_tt_blosum62score[j],seed_template_hit_span[j],
					unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues	[j],
					INI_temphit_ca_GDT_TS[j],						
					seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],
					MSA_Score1[j],rank_similarity_score[j], i,additional_span[j],k+1);
					good_templates[j]=1;
				}



/*

//More Z-Score is better

					// 0 better than 1 and 0 is DNC hit. Then 1 is bad. 
					if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][0]] > 
					      rank_similarity_score[MSA_redundant_hit_entries[k][1]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)  		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;

					// 0 better than 1 and 1 is DNC hit. Then 1 is bad. 
					if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][0]] > 
					      rank_similarity_score[MSA_redundant_hit_entries[k][1]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0)  		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;

					// 1 better than 0 and 0 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]] > 
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)   		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

					// 1 better than 0 and 1 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]] > 
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0)   		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;



//More TM_Score is better
					// 0 better than 1 and 0 is DNC hit. Then 1 is bad. 
					if( ((rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]] > 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)  		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;

					// 0 better than 1 and 1 is DNC hit. Then 1 is bad. 
					if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					       rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]] > 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0)  		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;

					// 1 better than 0 and 0 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]] > 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)   		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

					// 1 better than 0 and 1 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]] > 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]) 	)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0)   		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;
/*
//---------------------------------------------
//More GDT-TS Score is better if two redundant hits have equal TM_Score.
					// 0 better than 1 and 0 is DNC hit. Then 1 is bad. 
				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]>
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  	)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)  	 	)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;

					// 0 better than 1 and 1 is DNC hit. Then 1 is bad. 
				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
                                            (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]>
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  	)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0)  	 	)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;


					// 1 better than 0 and 0 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]]>
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]) 	) 
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)  	 	)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

					// 1 better than 0 and 1 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]]>
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]) 	) 
					  || (distant_templates[MSA_redundant_hit_entries[k][1]]>0)  	 	)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;


//---------------------------------------------
//More Sequence_Idenity is better if two redundant hits have equal TM_Score, GDT-TS Score
					// 0 better than 1 and 0 is DNC hit. Then 1 is bad. 
				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]]>
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]])  	)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0)  		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;

					// 0 better than 1 and 1 is DNC hit. Then 1 is bad. 
				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]]>
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]])  	)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0)  		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;


					// 1 better than 0 and 0 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]]>
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]])    	) 
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

					// 1 better than 0 and 1 is DNC hit. Then 0 is bad. 

				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]]>
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]])    	) 
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

//---------------------------------------------
//Lesser CA_RMSD is better if two redundant hits have equal TM_Score, GDT-TS Score, Sequence Identity 

					// 0 better than 1 and 0 is DNC hit. Then 1 is bad. 
				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][0]] < 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][1]])		) 
					 && (distant_templates[MSA_redundant_hit_entries[k][0]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;
					
					// 0 better than 1 and 1 is DNC hit. Then 1 is bad. 
				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][0]] < 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][1]])		) 
					 && (distant_templates[MSA_redundant_hit_entries[k][1]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;


					// 1 better than 0 and 0 is DNC hit. Then 0 is bad. 

				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]])     &&  
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][1]] < 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][0]]) 		)
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

					// 1 better than 0 and 1 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]])     &&  
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][1]] < 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][0]]) 		)
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;



//---------------------------------------------
//Lesser seed_hit distance map is better if 2 redundant hits have equal TM_Score,GDT-TS,Sequence Identity,CA_RMS 
					// 0 better than 1 and 0 is DNC hit. Then 1 is bad. 

				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][0]]== 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][1]]) 	       &&	
		     (seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][0]] < 
		      seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][1]]) )
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;
					

					// 0 better than 1 and 1 is DNC hit. Then 1 is bad. 

				   else	if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]])     &&
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][0]]== 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][1]]) 	       &&	
		     (seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][0]] < 
		      seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][1]]) )
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][1]]=-1;
					

					// 1 better than 0 and 0 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]])     &&  
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][1]]== 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][0]])	       &&
		     (seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][1]] < 
		      seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][0]]) ) 
					  && (distant_templates[MSA_redundant_hit_entries[k][0]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;

			
					// 1 better than 0 and 1 is DNC hit. Then 0 is bad. 
				   else if( ( (rank_similarity_score[MSA_redundant_hit_entries[k][1]]==
					      rank_similarity_score[MSA_redundant_hit_entries[k][0]]) &&
					    (seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][0]]== 
					     seed_hit_opti_TM_Score[MSA_redundant_hit_entries[k][1]])      &&
					     (INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][0]]==
					      INI_temphit_ca_GDT_TS[MSA_redundant_hit_entries[k][1]])  &&
					     (MSA_ttidentpercent[MSA_redundant_hit_entries[k][1]]==
					      MSA_ttidentpercent[MSA_redundant_hit_entries[k][0]])     &&  
					     (INI_CA_RMS[MSA_redundant_hit_entries[k][1]]== 
					      INI_CA_RMS[MSA_redundant_hit_entries[k][0]])	       &&
		     (seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][1]] < 
		      seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[MSA_redundant_hit_entries[k][0]]) ) 
					  && (distant_templates[MSA_redundant_hit_entries[k][1]]>0) 		)
					good_templates[MSA_redundant_hit_entries[k][0]]=-1;



//---------------------------------------------
	// Add some more template filtering conditions here if all these TM_Score, GDT_TS, Sequence Idenity, CA_RMS, 
	// Distance Map Scores become exactly equal for two template hits later. 
			}

		}

		else if((i>0)  && (distant_templates[j]>0) && (distant_redundant_hits[j]>0))
		{
		printf("\n%6s|%4d| %4d |%5.2f|%6.2f|%6.3f|%6.3f|%6.2f|%4d  |%6.3f|%3d|%6.3f|%7.3f|%5.4f|%7.3f|%6.3f|%3d |%3d =>RH, DNC,",	MSA_tempnames[j],MSA_actual_templatelen[j],MSA_aligned_commonsites[j],
			average_fold_length[j], MSA_ttidentpercent[j],
			MSA_unspanned_residues[j],MSA_tt_blosum62score[j],seed_template_hit_span[j],
			unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
			seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j],
			rank_similarity_score[j], i, additional_span[j]);
		}
*/

	}
	if(distant_templates_count>0)
	printf("\n\n\t\t\t\tDNC: DO NOT CONSIDER THIS HIT FOR TEMPLATE COMBINATION SCRIPT\n");


	//printf("redundant_hits[i][j]:");
	//for(i=0;i<MSA_tempcount;i++)
	//{
	//	for(j=0;j<MSA_tempcount;j++)
	//	printf("\t%d",redundant_hits[i][j]);
	//}


for(i=0;i<MSA_tempcount;i++)
{
		j=MSA_rank_tempdecre_order[i];	
		printf("\n%s has %d",MSA_tempnames[j],good_templates[j]);
}
/*
printf("\n_______________________");
for(i=0;i<MSA_tempcount;i++)
{
		printf("\n%s has %d",MSA_tempnames[i],good_templates[i]);
}
*/
















//Selecting insignificant negative Z-Score DNC templates with additional aligned target residues unaligned by positive Z-Score templates
int neg_z_score_hits_count=0;int neg_z_score_hits[MSA_tempcount];
count=0;count1=0;

for(i=0;i<MSA_tempcount;i++)
{
	if(rank_similarity_score[i]<0)
	{
		neg_z_score_hits[i]=(-1);	//Store 1 in neg_z_score_hits for negative z_score DNC hits.
		count++;
	}
	else
	{
		neg_z_score_hits[i]=1;
		count1++;
	}
}
neg_z_score_hits_count=count;
int correct_neg_z_score_hits[neg_z_score_hits_count];	// Array to store position of correct DNC hit number 
int top_templates_count=count1;
printf("\ntop_templates_count:%d==========>",top_templates_count);

int j1=0;k1=0;j=0;k=0;count=0;count1=0;
int additional_aligned_target_residues_over_posZ_hits[neg_z_score_hits_count];
for(i=0;i<neg_z_score_hits_count;i++)
additional_aligned_target_residues_over_posZ_hits[i]=(-1);


for(i=0;i<MSA_tempcount;i++)
{
	count=0;
	j1=MSA_rank_tempdecre_order[i];	
	if(rank_similarity_score[j1]<0)
	{
		count1=0;
		for(j=0,k=0;	j<MSA_targetlen,k<MSA_targetlen;	j++,k++)
		{
			if(  (MSA_templatearray[j1][j]!='-')  && (MSA_targetarray[k]!='-')   )
			{
				count=0;	
				for(k1=MSA_rank_tempdecre_order[0];k1<MSA_rank_tempdecre_order[top_templates_count];k1++)
				{
					if( (MSA_templatearray[k1][j]=='-') )
					count++;
				}
			}
			if(count==top_templates_count)
			count1++;
		}
	correct_neg_z_score_hits[j1]=1;
	additional_aligned_target_residues_over_posZ_hits[j1]=count1;
	count1=0;
	printf("\nTemplate %s has additional_aligned_target_residues_over_posZ_hits:%d",MSA_tempnames[j1],
	additional_aligned_target_residues_over_posZ_hits[j1]);

	if(additional_aligned_target_residues_over_posZ_hits[j1]<5)
	distant_templates[j1]=j1;
	
	}
}
	











//additional_span_position,additional_span_percentage[i]
int added_res_identity[MSA_tempcount];
float added_res_ident_percentage[MSA_tempcount];
for(i=0;i<MSA_tempcount;i++)
added_res_ident_percentage[i]=(-1);

for(i=0;i<MSA_tempcount;i++)
{
	count=0;a1=0;b1=0;
	for(j=0,k=0;j<MSA_templatelen[i],k<MSA_targetlen;j++,k++)
	{
		if( (additional_span_position[i][j]>=0) && (MSA_templatearray[i][j]==MSA_targetarray[k]) )
		count++;
	}
	added_res_identity[i]=count;
	a1=count;
	b1=additional_span[i];
	added_res_ident_percentage[i]=a1/b1;
}




//BLOSUM62 Score of a hit to target at additional residues over seed template.
char  f1[50]="Added_Span_BLOSUM_Score_";	//Save Added residues BLOSUM Score in a new file
char  f2[50]="Information.ali";
char *f3=strcat(f1,f2);
FILE *newf1=fopen(f3,"w");

fswap=0;float added_res_blosum62score[MSA_tempcount];float fswap1=0;
for(i=0;i<MSA_tempcount;i++)
{
	count=0;fswap=0;
	for(j=0,k=0;	j<MSA_templatelen[i],k<MSA_targetlen;	j++,k++)
	{	
		if( (additional_span_position[i][j]>=0) && (additional_span_position[i][k]>=0)  )
		{	
			// Identity Scores
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+9;
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+8;
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+6;
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+7;
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+4;
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+5;
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+11;
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+7;
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+4;
	
	
			//Uptil 5th Row Horizontal lines
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(1);	
	
	
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(1);	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);	

			//6th Row Horizontal lines
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(0);	

			//7th Row Horizontal lines FROM N
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(1);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(0);

			//Edited till here for the main() gap
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);	
	
			//8th Row Horizontal lines FROM D
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(1);	

			//9th Row Horizontal lines FROM E
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-4);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-1);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);	
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(2);	

			//10th Row Horizontal lines from Q
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(2);	

			//11th Row Horizontal lines from H
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(0);	

			//12th Row Horizontal lines from R

			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(0);	
	
	
	
			//////////////////////////////////////////////K STARTS

			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(2);	

			// M STARTS
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	
	
	
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);	


			//I STARTS
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(1);	
	
			//L STARTS

			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(2);	
	
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(2);	
	
			//V STARTS
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(3);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(3);	
	
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(1);	
	
			//F STARTS
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(0);	
	
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(0);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(0);	


			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(-1);	

			//Y STARTS
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	


			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	


			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(-1);	

			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(3);
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(3);	


			//W STARTS
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='C')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='C') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='S')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='S') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='T')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='T') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='P')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='P') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='A')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='A') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='G')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='G') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='N')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='N') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='D')) 
			fswap=fswap+(-4);
			if((MSA_templatearray[i][j]=='D') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-4);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='E')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='E') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='Q')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='Q') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='H')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='H') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='R')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='R') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='K')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='K') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='M')) 
			fswap=fswap+(-1);
			if((MSA_templatearray[i][j]=='M') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-1);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='I')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='I') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='L')) 
			fswap=fswap+(-2);
			if((MSA_templatearray[i][j]=='L') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-2);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='V')) 
			fswap=fswap+(-3);
			if((MSA_templatearray[i][j]=='V') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(-3);	

			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='F')) 
			fswap=fswap+(1);
			if((MSA_templatearray[i][j]=='F') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(1);	
	
			if((MSA_templatearray[i][j]=='W') && (MSA_targetarray[k]=='Y')) 
			fswap=fswap+(2);
			if((MSA_templatearray[i][j]=='Y') && (MSA_targetarray[k]=='W')) 
			fswap=fswap+(2);	
			
			if((i>0) && (additional_span[i]>=4))
			{
				fprintf(newf1,"\nTemplate:%s residue %c:: Target residue %c => BLOSUM_Score=%f",
				MSA_tempnames[i],MSA_templatearray[i][j],MSA_targetarray[k],fswap);
			}
			fswap1=fswap;

		}
		added_res_blosum62score[i]=fswap;
		//if(added_res_blosum62score[i]<0)
		//added_res_blosum62score[i]=log(-added_res_blosum62score[i]);	
	}	
	printf("\nTemplate:%s,added_temp_hit_BLOSUM62_Score:%f",MSA_tempnames[i],added_res_blosum62score[i]);
	if((i>0) && (additional_span[i]>=4))
	fprintf(newf1,"\n________________________________________________________________________________________");
}

if(fclose(newf1))
printf("\nFile Close Error.\n");


//Removes all insignificantly scoring hits from the set when considered template count is more than 10.
for(i=0;i<MSA_tempcount;i++)
{
	if( ((MSA_tempcount>10)&&(rank_similarity_score[i]<0)) || (additional_span[i]<4)  ) 
	distant_templates[i]=i;
}
//Removes all insignificantly scoring hits from the set when considered template count is more than 10 is Done Here





//seed_hit_opti_TM_Score[i]

if (system( "clear" )) system( "cls" );
printf("\n");
if (system( "clear" )) system( "cls" );

printf("\n");
if (system( "clear" )) system( "cls" );
printf("\n\t\t\t\tSCAR MULTIPLE TEMPLATE PROTEIN MODELLING COMBINATION ANALYZER");
printf("\n\t\t\t\t      Dr. Shibasish Chowdhury, Ashish Runthala, BITS PILANI");
printf("\n\t\t\tCOMPLETE COMPILED RESULT OF TEMPLATE HITS AGAINST THE TARGET  |    TARGET LENGTH:%4d",MSA_actual_targetlen);

printf("\n________________________________________________________________________________________________________________________     ");
printf(" RESULTS==>| \t\tSEQUENCE ANALYSIS           |STRUCTURAL TOPOLOGY ANALYSIS|  OVERALL   |   ADDED TARGET         |"); 
printf("\n___________|________________________________________|___AGAINST SEED TEMPLATE____|___SCORE ___|_RESIDUE ANALYSIS_______|");
printf("\n TEMP |TEMP| AVE.|TARG | UN |BLSM |BLSM | SEED |UNIQ|     |CA |  CA |SEED |      | MSA |  Z   |ADDED|IDEN|SEQ.   |ADDED|");
printf("\n      |LEN |CHUNK|TEMP |SPAN|SCORE|SCORE| COVER|RES.| CA  |GDT| GDT |HIT  |      |SCORE| SCORE|TARG.|TITY|BLSM.  |RES. |");
printf("\n      |    | LEN |IDEN |RES.|TARG |SEED | SPAN |    |RMSD |RES|SCORE|MAP  |  TM  |     |      | RES.|RES.|SCORE  |OVER |");	
printf("\n      |    |     |TITY |    |TEMP |TEMP |      |    |     |   |     |AVE. |SCORE |     |      |     |    |       |SIGNI|");
printf("\n______|____|_____|_____|____|_____|_____|______|____|_____|___|_____|DIFF |______|_____|______|_____|____|_______|_HITS|");

j=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		j=MSA_rank_tempdecre_order[i];	
		if(i==0)
		printf("\n%6s|%4d|%5.1f|%5.2f|%4.2f|%5.2f| SEED| SEED |SEED|%4.3f|%3d|%5.1f|%5.2f|%5.4f| SEED| SEED |SEED |SEED|  SEED |", MSA_tempnames[j],MSA_actual_templatelen[j],
		average_fold_length[j],	MSA_ttidentpercent[j],MSA_unspanned_residues[j],
		MSA_tt_blosum62score[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j]);

		else if((i>0) && (distant_templates[j]==0) && (rank_similarity_score[j]>0) )
		printf("\n%6s|%4d|%5.1f|%5.2f|%4.2f|%5.2f|%5.2f|%6.2f|%3d |%5.3f|%3d|%5.2f|%5.2f|%5.4f|%5.3f|%6.3f|%5d|%3d | %6.3f|",
		MSA_tempnames[j],MSA_actual_templatelen[j], 
		average_fold_length[j],MSA_ttidentpercent[j],  			
		MSA_unspanned_residues[j],MSA_tt_blosum62score[j],MSA_st_blosum62score[j],seed_template_hit_span[j],
		unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j], 			rank_similarity_score[j], additional_span[j],added_res_identity[j],added_res_blosum62score[j]);

		else if((i>0) && (distant_templates[j]>0) && (rank_similarity_score[j]>0) )
		printf("\n%6s|%4d|%5.1f|%5.2f|%4.2f|%5.2f|%5.2f|%6.2f|%3d |%5.3f|%3d|%5.2f|%5.2f|%5.4f|%5.3f|%6.3f|%5d|%3d | %6.3f| DNC",
		MSA_tempnames[j],MSA_actual_templatelen[j], 
		average_fold_length[j], MSA_ttidentpercent[j],
		MSA_unspanned_residues[j],MSA_tt_blosum62score[j],MSA_st_blosum62score[j],seed_template_hit_span[j],
		unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j],
		rank_similarity_score[j], additional_span[j],added_res_identity[j],added_res_blosum62score[j]);

		else if((i>0) && (distant_templates[j]>0) && (rank_similarity_score[j]<0))
		printf("\n%6s|%4d|%5.1f|%5.2f|%4.2f|%5.2f|%5.2f|%6.2f|%3d |%5.3f|%3d|%5.2f|%5.2f|%5.4f|%5.3f|%6.3f|%5d|%3d | %6.3f|%3d_DNC",
		MSA_tempnames[j],MSA_actual_templatelen[j], 
		average_fold_length[j], MSA_ttidentpercent[j],
		MSA_unspanned_residues[j],MSA_tt_blosum62score[j],MSA_st_blosum62score[j],seed_template_hit_span[j],
		unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j],
		rank_similarity_score[j], additional_span[j],added_res_identity[j],added_res_blosum62score[j],additional_aligned_target_residues_over_posZ_hits[j]);


		else if((i>0) && (distant_templates[j]<=0) && (rank_similarity_score[j]<0)  )
		printf("\n%6s|%4d|%5.1f|%5.2f|%4.2f|%5.2f|%5.2f|%6.2f|%3d |%5.3f|%3d|%5.2f|%5.2f|%5.4f|%5.3f|%6.3f|%5d|%3d | %6.3f|%3d",
		MSA_tempnames[j],MSA_actual_templatelen[j], 
		average_fold_length[j], MSA_ttidentpercent[j],
		MSA_unspanned_residues[j],MSA_tt_blosum62score[j],MSA_st_blosum62score[j],seed_template_hit_span[j],
		unique_residues[j],INI_CA_RMS[j],INI_temphit_ca_GDT_residues[j],INI_temphit_ca_GDT_TS[j],
		seed_temp_temp_hit_ave_dist_lt_threshold_analysis_average[j],seed_hit_opti_TM_Score[j],MSA_Score1[j],
		rank_similarity_score[j], additional_span[j],added_res_identity[j],added_res_blosum62score[j],additional_aligned_target_residues_over_posZ_hits[j]);


	}
	
	if(distant_templates_count>0)
	printf("\n\n\t\t\t\tDNC: DO NOT CONSIDER THIS HIT FOR TEMPLATE COMBINATION SCRIPT.");

	printf("\n\n");







count=0;
for(i=0;i<MSA_tempcount;i++)
{
	if(additional_span[i]>=5)
	count++;
}






if(count>0)
{


	char *new12=argv[1];
	char newn2[50]="_Parsed_Alignment.ali";
	char* new32=strcat(new12,newn2);
	FILE *newalifile=fopen(new32,"w");

       fprintf(newalifile,"%s", MSA_tempseqarr[0]);
       fprintf(newalifile,"*");
       fprintf(newalifile,"\n");

       for(i=1;i<MSA_tempcount;i++)
       {
	  if(additional_span[i]>=4)
	  {
	     for(j=0;j<6;j++)
	     fprintf(newalifile,"%c", MSA_tempseqarr[i][j]);
	   
	     for(j=0;j<MSA_templatelen[i];j++)
	     {

		     if(MSA_templatearray[0][j]=='-')
		     {
				if(MSA_templatearray[i][j]!='-')
				{
					if(MSA_targetarray[j]!='-')
					fprintf(newalifile,"%c", MSA_templatearray[i][j]);
					else if(MSA_targetarray[j]=='-')
					fprintf(newalifile,"-");
				}
				else if (MSA_templatearray[i][j]=='-')
				{
					if(MSA_targetarray[j]!='-')
					fprintf(newalifile,"-");
					else if(MSA_targetarray[j]=='-')
					fprintf(newalifile,"-");
				}
		      }	
		     else if(MSA_templatearray[0][j]!='-')
		     {
				if(MSA_templatearray[i][j]!='-')
				{
					if(MSA_targetarray[j]!='-')
					fprintf(newalifile,"-");
					else if(MSA_targetarray[j]=='-')
					fprintf(newalifile,"-");
				}
				else if (MSA_templatearray[i][j]=='-')
				{
					if(MSA_targetarray[j]!='-')
					fprintf(newalifile,"-");
					else if(MSA_targetarray[j]=='-')
					fprintf(newalifile,"-");
				}
		     }
	     }
	     if(i<(MSA_tempcount-1))
	     fprintf(newalifile,"*\n");
	  }
	}
	fprintf(newalifile,"\nTARGT>");
	fprintf(newalifile,"%s",MSA_targetarray);
	fprintf(newalifile,"*\n");		
	
	//printf("%s",MSA_tempseqarr[0]);
	if(fclose(newalifile))
	printf("\nFile Close Error.\n");

}







/*
char new11[50]="SEED_TEMPLATE_CA_MODEL.pdb";
char *new111=argv[1];
char* new2=strcat(new111,new11);
FILE *newfile3=fopen(new2,"w");

k=0; int seedcapos[lm];
for(k=0;k<lm;k++)
seedcapos[k]=(-1);
struct atom *matm1 = mpdbToArray2(MSA_pdbfiles[0]);


k=0;
for(k=0;k<lm;k++)
{
	if(strstr(matm1[k].mol,"CA")!=NULL)
	{
		seedcapos[k]=k;
		//printf("=>");
	}
}
int countatom=0;int countamino=0;k=0;
*/

if(distant_templates_count==(MSA_tempcount-1) )
{
	printf("\n\t\t\t\t SINGLE SEED TEMPLATE IS ENOUGH TO MODEL THIS TARGET SEQUENCE\n\n");
/*	for(j=0;j<MSA_templatelen[i];j++)
	{
		if( (MSA_templatearray[0][j]!='-') && (MSA_targetarray[j]!='-') && (matm[j].mol=="CA") )
		{
			if( (MSA_targetarray[j]=='A') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s ALA  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='R') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s ARG  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='N') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s ASN  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='D') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s ASP  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='C') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s CYS  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='Q') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s GLN  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='E') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s GLU  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='G') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s GLY  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='H') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s HIS  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='I') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s ILE  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='L') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s LEU  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='K') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s LYS  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='M') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s MET  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='F') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s PHE  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='P') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s PRO  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='S') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s SER  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='T') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s THR  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='W') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s TRP  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='Y') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s TYR  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
			if( (MSA_targetarray[j]=='V') && (seedcapos[k]>0) )
			{
				fprintf(newfile3,"ATOM  %5.0d %4s VAL  %4.0d    %8.3f%8.3f%8.3f%6.2f%6.2f%2s\n", matm[j].an,
				matm[j].mol,countamino, matm[j].xc, matm[j].yc,matm[j].zc,matm[j].occ,
				matm[j].temp,matm[j].element);
				countamino++;k++;
			}
		}
	}
	fprintf(newfile3,"\n");		
	if(fclose(newfile3))
	printf("\nFile Close Error.\n");
*/
}
//A,R,N,D,C,Q,E,G,H,I,L,K,M,F,P,S,T,W,Y,V	









/*
k1=0;
for(i=0;i<MSA_tempcount;i++)
{
	j=MSA_rank_tempdecre_order[i];	
	if((i>0) && (distant_redundant_hits[j]>0))
	{
		//MSA_redundant_hit_entries[MSA_redundant_hit_entries_pair_count][2]
		for(k=0;k<MSA_redundant_hit_entries_pair_count;k++)
		{
			if(  (j==MSA_redundant_hit_entries[k][0]) || (j==MSA_redundant_hit_entries[k][1])  )
			printf("\nTempnames:%s,%s",MSA_tempnames[i],MSA_tempnames[j]);
		}
	}

}


	
/*

	int corresponding_cover_span_difference_of_hit_against_seed_template[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		a1=MSA_templatelen[i] - MSA_seqstartpos[i] - MSA_seqendpos[i] + 1;
		b1=MSA_templatelen[0] - MSA_seqstartpos[0] - MSA_seqendpos[0] + 1;
		corresponding_cover_span_difference_of_hit_against_seed_template[i]=a1-b1;
		printf("\nTemp %s has %d corresponding_cover_span_difference_of_hit_against_seed_template",
		MSA_tempnames[i], corresponding_cover_span_difference_of_hit_against_seed_template[i]);
	}

	//Corresponding cover span of a template hit against the target sequence
	int corresponding_cover_span_of_hit_against_target[MSA_tempcount];
	int target_residue_start_position[MSA_tempcount]; int target_residue_end_position[MSA_tempcount];

	for(i=0;i<MSA_tempcount;i++)
	{
		count=0;j=0;
	        while ( (MSA_templatearray[i][j]=='-') && (MSA_targetarray[j]=='-')  )
	        {
			count++;
			j++;
		}
		target_residue_start_position[i]=count;
		//printf("\nTemp %s Start is found at %d position out of %d",MSA_tempnames[i],
		//target_residue_start_position[i],MSA_templatelen[i]);
	}

	count=0;k=0;i=0;j=0;
	for(i=0;i<MSA_tempcount;i++)
	{
		j=MSA_templatelen[i]-1;
	        while ( (MSA_templatearray[i][j]=='-') && (MSA_targetarray[j]=='-')  )
	        {
			count++;
			j--;
		}
		target_residue_end_position[i]=count;
		//printf("\nTemp %s has Ending Residue is found at %d position out of %d",MSA_tempnames[i], 			target_residue_end_position[i],MSA_templatelen[i]);
		count=0;j=0;
	}

	printf("\n____________________");
	for(i=0;i<MSA_tempcount;i++)
	{
		a1=MSA_templatelen[i] - MSA_seqstartpos[i] - MSA_seqendpos[i] + 1;
		b1=MSA_templatelen[i] - target_residue_end_position[i] - target_residue_end_position[i] + 1;
		corresponding_cover_span_of_hit_against_target[i]=a1-b1;
		printf("\nTemp %s has corresponding_cover_span_difference_of_hit_against_ against seed:%4d target:%4d",
		MSA_tempnames[i], corresponding_cover_span_difference_of_hit_against_seed_template[i], 			     corresponding_cover_span_of_hit_against_target[i]);
	}
	
	count=0;float MSA_seed_hit_aligned_percentage[MSA_tempcount];
	for(i=0;i<MSA_tempcount;i++)
	{
		for(j=0,k=0;j<MSA_templatelen[i],k<MSA_targetlen;j++,k++)
		{
			if( (MSA_templatearray[0][j]!='-') && (MSA_templatearray[i][j]!='-'))
			count++;
		}		 
		MSA_seed_hit_aligned_percentage[i]=(2*count)/(MSA_actual_templatelen[0]+MSA_actual_templatelen[i]);
		printf("\nTemp:%s has MSA_seed_hit_aligned_percentage[%d]:%6.4f",MSA_tempnames[i],i,MSA_seed_hit_aligned_percentage[i]);
	}










/*

	k1=0;
	int swappos1 =0;
	int swappos2 =0;
	printf("\n\n\tSTRUCTURALLY SIMILAR TEMPLATE CLUSTERS:");
	for(i=0;i<MSA_tempcount;i++)
	{
		numswap1=0;
		for(k=0;k<MSA_tempcount;k++)
		{
			if( (MSA_highly_seq_identical_hits[i][k]==2) && (i!=k) )
			{
				numswap1++;
			}
		}
		if( (numswap1>0) && (swappos1!=i) && (swappos2!=i)  )
		{
			printf("\n%10d: %6s,",k1+1,MSA_tempnames[i]);
			swappos1=i;	
			k1++;
		}
		for(k=0;k<MSA_tempcount;k++)
		{
			if( (MSA_highly_seq_identical_hits[i][k]==2) && (i!=k)  )
			{
				printf("%6s",MSA_tempnames[k]);
				swappos2=j;	

				if(seed_hit_opti_TM_Score[i] < seed_hit_opti_TM_Score[k])
				{
					printf("\tKeep template %s", MSA_tempnames[k]);
				}
				else if (seed_hit_opti_TM_Score[k] < seed_hit_opti_TM_Score[i])
				{
					printf("\tKeep template %s", MSA_tempnames[i]);
				}

			}

		}		
	}

	printf("\n");











printf("\n\n");
/*
*/

return 1;
}	
