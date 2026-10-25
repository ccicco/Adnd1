    // ---- R774 file-patch seam audit ----
    // THE TOOLING ROUND - the R775 mount site needs spec-declared extra-file
    // patches (game/party.h, game/state_combat.cpp, and the R403 charge
    // conditions in regtest), which the ritual could not land: the engine
    // patched only seed, header, gap flips, include, and audit, and ./rn
    // git-added only those five. R774 extends the three tools - the engine
    // gains the file_patches spec key (byte-exact from, one replace,
    // idempotent by to-presence, counted in the applied/already census),
    // rverify restores and counts the patch targets, and ./rn derives the
    // extra git-add paths from the spec. The pins below codify the seam
    // contract; the demo patch rides rules/mountlayer.h (comment-only - the
    // R403 audit at 43208 requires the charge open until R775).
    {
        using namespace rules;
        int bad = 0;
    if (dnlPatchedToolCount() != 3
            || dnlFirstFilePatchRound() != 774
            || dnlMountSiteRound() != 775
            || !dnlFilePatchesSpecDeclared()
            || !dnlFilePatchAnchorByteExact()
            || !dnlFilePatchesCountedAsPatches()
            || !dnlFilePatchesGoInTheGitAdd()
            || !dnlMountlayerSeamNotesR775()
        )
            ++bad;
        printf("R774 file-patch seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
