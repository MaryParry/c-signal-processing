{
  description = "Digital signal processing in C";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          gcc gnumake gdb
          clang-tools  # clangd for editor support
          (python3.withPackages (ps: [ ps.matplotlib ]))  # only for plotting
        ];
        # Nix enables _FORTIFY_SOURCE by default, which warns at -O0 (debug builds)
        hardeningDisable = [ "fortify" ];
      };
    };
}
