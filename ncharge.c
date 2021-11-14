void ncharge(){
const char *files[14]={"pytree;100","pytree;99","pytree2040;28","pytree2040;27","pytree4060;24","pytree4060;23","pytree020;24","pytree020;23","pytree6080;16","pytree6080;15","pytree80100;7","pytree80100;6","pytree100;3","pytree100;2"};
TH1D *hist1=new TH1D("hist1","positive charge distribution per event",15844510,0,15844510); //count of eta>1.5=60623206
TH1D *hist2=new TH1D("hist2","negative charge distribution per event",15844510,0,15844510);
TH1D *hist3=new TH1D("hist3","net charge distribution per event",15844510,0,15844510);
size_t count=0;
for(int k=0;k<12;k++){
TTree *t=new TTree("t","myTree");
TFile *f=new TFile("/home/rhishabh/ph219_project/file1/13TeV_CR0_RHoff.root"); 
Int_t pid[192];
Int_t ntrack;
Double_t pT[192]; 
Double_t rap[192];
Double_t eta[192];
Double_t phi[192];
gDirectory->GetObject(files[k],t);
t->SetBranchAddress("pid",pid);
t->SetBranchAddress("pT",pT);
t->SetBranchAddress("eta",eta);
t->SetBranchAddress("rap",rap);
t->SetBranchAddress("phi",phi);
t->SetBranchAddress("ntrack",&ntrack);
size_t n=(size_t)t->GetEntries();
Int_t np;
Int_t nn;
Int_t net;
for(size_t i=0;i<n;i++){
np=0;
nn=0;   
net=0; 
t->GetEntry(i);
for(size_t j=0;j<ntrack;j++){
    if(pid[j]>0){
        np=np+1;
    }
    else if (pid[j]<0){
        nn=nn+1;
    }
}
net=np-nn;    
hist1->Fill(count,np);
hist2->Fill(count,nn);
hist3->Fill(count,net);
count++;
}
}
TCanvas *c2=new TCanvas("c2","Charge distributions");
c2->Divide(1,3);
c2->cd(1);
hist1->Draw();
c2->cd(2);
hist2->Draw();
c2->cd(3);
hist3->Draw();
}